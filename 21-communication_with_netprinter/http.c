#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char buf[500];
	char tmp[100];
	char *res = "ipaddress=192.168.1.1";

	memset(buf,'\0',500);
	sprintf(buf,"%sHost:%d","POST /aijiabao/api/mac/senddata HTTP/1.0\r\n",192);
	sprintf(buf,"%s.%d",buf,168);
	sprintf(buf,"%s.%d",buf,1);
	sprintf(buf,"%s.%d",buf,112);
	sprintf(buf,"%s%s",buf,":8089\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length:50\r\n\r\n01010101010101010101010102020202020202");

	printf("%s\n",buf);

	sscanf(res,"%[^=]",tmp);
	printf("%s\n",tmp);

	return 0;
}
