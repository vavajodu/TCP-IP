#include"header.h"
void main()
{
	int fd,nfd,len;
	char data[20];
	struct sockaddr_in v,v1;
	fd=socket(AF_INET,SOCK_STREAM,0);	
	if(fd<0)
	{
		perror("socket");
		return;
	}
	v.sin_family=AF_INET;
	v.sin_port=htons(2700);
	v.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof(v);
	connect(fd,(const struct sockaddr *)(&v),len);
	perror("connect");
	printf("enter the data\n");
	scanf(" %[^\n]",data);
	write(fd,data,strlen(data)+1);
	close(nfd);
}
	
