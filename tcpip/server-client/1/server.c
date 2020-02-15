#include"header.h"

int my_atoi(const char *p);
main()
{
	int fd,nfd,len;
	struct sockaddr_in v,v1;
	char ch[10],ip[30];
	
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		perror("socket");
		return;
	}
	perror("socket");
	v.sin_family=AF_INET;
	v.sin_port=htons(2500);
	v.sin_addr.s_addr=inet_addr("0.0.0.0");
	len =sizeof(v);
	
	if(bind(fd,(const struct sockaddr *)(&v),len))
	{
		perror("bind");
		return;
	}
	perror("bind");
	listen(fd,5);
	nfd=accept(fd,(struct sockaddr *)(&v1),&len);
	if(nfd<0)
	{
		perror("accept");
		return ;
	}
	perror("accept");
	printf("Connection accepted from %s\n",inet_ntop(AF_INET,(&v1.sin_addr),ip,sizeof(ip)));
	read(nfd, ch,sizeof(ch));
	printf("Data: %s\n",ch);
}
