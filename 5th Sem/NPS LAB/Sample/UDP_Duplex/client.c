#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 50

main()
{
	int sockfd,retval,i;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr, clientaddr;
	char buff[MAXSIZE];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\nSocket Creation Error");
		return;

	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3389);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	if(bind(sockfd,(struct sockaddr*)&clientaddr,sizeof(clientaddr)) == -1)	{
		printf("Binding error");
		close(sockfd);
		exit(1);
	}

	while(1){
		printf("enter the text\n");
		fgets(buff, MAXSIZE, stdin);
		if(sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr))==-1){
			printf("sending error");
			close(sockfd);
			exit(1);
		}

		if (strcmp(buff, "stop\n") == 0)
			break;

		int size=sizeof(serveraddr);
		recedbytes=recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&serveraddr,&size);
		fputs(buff, stdout);
		printf("\n");

		if (strcmp(buff, "stop\n") == 0)
			break;

	}
	close(sockfd);
}
