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
	v.sin_addr.s_addr=inet_addr("0.0.0.0");
	len=sizeof(v);
	bind(fd,(const struct sockaddr *)(&v),len);
	perror("bind");
	listen(fd,10);
	perror("listen");
	nfd=accept(fd,(struct sockaddr *)(&v1),&len);
	perror("accept");
	read(nfd,data,sizeof(data));
	printf("data:%s\n",data);
	close(nfd);
}
	
