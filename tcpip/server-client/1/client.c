#include"header.h"

int my_atoi(const char *p);
main()
{
	int fd,len;
	struct sockaddr_in v;
	char ch[10];
	
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		perror("socket");
		return;
	}
	perror("socket");
	
	v.sin_family=AF_INET;
	v.sin_port=htons(2500);
	v.sin_addr.s_addr=inet_addr("127.0.0.1");
	len =sizeof(v);	
	if(connect(fd,(const struct sockaddr *)(&v),len))
	{
		perror("connect");
		return;
	}
	perror("connect");
	printf("Enter the data...\n");
	gets(ch);
	write(fd, ch,strlen(ch)+1);
}
