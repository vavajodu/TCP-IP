#include"header.h"
int my_atoi(char *p)
{
	int sum=0,i;
	for(i=0;p[i];i++)
	{
		sum=sum*+p[i]-48;
	}
	return sum;
}
main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("Usage: ./a.out port_no\n");
		return;
	}
	int sfd,len,port,nsfd;
	struct sockaddr_in v,v1;
	char s[10];
	port=my_atoi(argv[1]);
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
		perror("socket");
	v.sin_family=AF_INET;
	v.sin_port=htons(port);
	v.sin_addr.s_addr=inet_addr("0.0.0.0");
	len=sizeof(v);
	printf("hhh\n");
	
	bind(sfd,(const struct sockaddr *)(&v),len);
	perror("bind");
	listen(sfd,10);
	perror("listen");
	nsfd=accept(sfd,(struct sockaddr *)(&v1),&len);
	perror("accept");
	read(nsfd,s,sizeof(s));
	printf("Data:%s\n",s);
}
