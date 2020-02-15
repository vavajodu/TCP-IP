#include"header.h"
main()
{
	int fd,ret;
	char s[10];
	struct timeval t;
	fd_set v;
	fd=open("f1",O_RDWR);
	perror("open");
	FD_ZERO(&v);
	FD_SET(0,&v);
	FD_SET(fd,&v);
	t.tv_sec=10;
	t.tv_usec=0;
	ret=select(10,&v,0,0,&t);
	if(ret<0)
	{
		perror("select");
		return;
	}
	else if(ret==0)
	{
		printf("Time out..\n");
	}
	else if(FD_ISSET(0,&v))
	{
		scanf("%s",s);
		printf("Data:%s\n",s);
	}
	else if(FD_ISSET(fd,&v))
	{
		read(fd,s,sizeof(s));
		printf("Data from FIFO :%s\n",s);
	}
}
