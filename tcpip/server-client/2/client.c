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
	int sfd,len,port;
	struct sockaddr_in v;
	char s[10];
	port=my_atoi(argv[1]);
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
		perror("socket");
	v.sin_family=AF_INET;
	v.sin_port=htons(port);
	v.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof(v);
	
	bind(sfd,(const struct sockaddr *)(&v),len);
	perror("bind");
	connect(sfd,(const struct sockaddr *)(&v),len);
	perror("connect");
	printf("Enter the data..\n");
	gets(s);
	write(sfd,s,strlen(s)+1);
}
