#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

// Driver code
int main() {
 int sockfd; char buff[20];
 int buffer[MAXLINE];
 //char *hello = "Hello from client";
 struct sockaddr_in servaddr;

 // Creating socket file descriptor
 if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {   perror("socket creation failed");
 exit(EXIT_FAILURE);
 }

 memset(&servaddr, 0, sizeof(servaddr));

 // Filling server information
 servaddr.sin_family = AF_INET;
 servaddr.sin_port = htons(PORT);
 servaddr.sin_addr.s_addr = INADDR_ANY;
 while(1){
 int n, len;
 printf("\n\n");
 printf("Enter new string: ");
 scanf("%s", buff);
 if(!strcmp(buff,"halt"))
 exit(0); 
 sendto(sockfd, (const char *)buff, strlen(buff),
 MSG_CONFIRM, (const struct sockaddr *) &servaddr,   sizeof(servaddr));
 //printf("Hello message sent.\n");

 n = recvfrom(sockfd, (char *)&buffer, MAXLINE,
 MSG_WAITALL, (struct sockaddr *) &servaddr,   &len);
//printf("%d%d%d",buffer[0],buffer[1],buffer[2]);
 //buffer[n] = '\0';
 if(buffer[0]==1)
printf("\nString is palindrome!");
else
printf("\nString is not a palindrome!" );
printf("\nLength of string is %d and it contains %d number of vowels.  ",buffer[1],buffer[2]);
 //printf("Server : %s\n", buffer);
 }
 close(sockfd);
 return 0;
}
