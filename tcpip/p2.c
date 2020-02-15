#include"header.h"
main()
{
	int fd;
	char s[10];
	fd=open("f1",O_RDWR);	
	perror("open");
	printf("Enter the data..\n");
	scanf("%s",s);
	write(fd,s,strlen(s)+1);
}
