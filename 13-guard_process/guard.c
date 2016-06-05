#include <apue.h>
#include <fcntl.h>
#include <syslog.h>
#include <signal.h>
#include <sys/resource.h>
#include <errno.h>

#define LOCKFILE "/var/run/daemon.pid"
#define LOCKMODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)

int already_running(void);
void daemonize(const char *cmd);

int main(int argc,char *argv[])
{
	daemonize("daemonize");
	if(already_running()==1){
		syslog(LOG_ERR,"daemon already running");
		exit(1);
	}
	
	sleep(600);
	
}

int already_running(void){
	int 	fd,ret;
	char 	buf[16];
	struct flock flock;

	fd = open(LOCKFILE,O_RDWR|O_CREAT,LOCKMODE);
	if(fd < 0)
	{
		syslog(LOG_ERR,"can't open %s:%s",LOCKFILE,strerror(errno));
		exit(1);
	}
	
	flock.l_type = F_WRLCK;
	flock.l_whence = SEEK_SET;
	flock.l_start = 0;
	flock.l_len = 0;	
	if((ret = fcntl(fd,F_SETLK,&flock)) < 0){
		if(errno == EACCES || errno == EAGAIN){
			close(fd);
			return 1;
		}
		syslog(LOG_ERR,"can't lock %s:%s",LOCKFILE,strerror(errno));
		exit(1);
	}

	printf("already running ret = %d\n",ret);

	ftruncate(fd,0);
	sprintf(buf,"%ld",(long)getpid());
	write(fd,buf,strlen(buf)+1);
	return 0;
}	

void daemonize(const char *cmd)
{
	int		 i,fd0,fd1,fd2;
	pid_t		 pid;
	struct rlimit	 r1;
	struct sigaction sa;
//
	umask(0);
	
	if(getrlimit(RLIMIT_NOFILE,&r1) < 0)
		perror("getrlimit");
//	
	if((pid = fork()) < 0)
		perror("fork");
	else if(pid > 0)
		exit(0);
//
	setsid();
//
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if(sigaction(SIGHUP,&sa,NULL) < 0)
		printf("sigaction error");

	if((pid = fork()) < 0)
		perror("fork");
	else if(pid > 0)
		exit(0);
//	
	if(chdir("/") < 0)
		perror("chdir");
//
	if(r1.rlim_max == RLIM_INFINITY)
		r1.rlim_max = 1024;
	for(i=0;i<r1.rlim_max;i++)
		close(i);
//	
	fd0 = open("/dev/null",O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);	
//	
	openlog(cmd,LOG_CONS,LOG_DAEMON);
	if(fd0 != 0 || fd1 != 1 || fd2 != 2){
		syslog(LOG_ERR,"unexpected file descriptors %d %d %d",fd0,fd1,fd2);
		exit(1);
	}
}

