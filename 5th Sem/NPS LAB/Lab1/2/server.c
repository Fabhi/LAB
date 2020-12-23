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
  int sockfd;
  char buffer[MAXLINE];
  //char *hello = "Hello from server";
  struct sockaddr_in servaddr, cliaddr;

  // Creating socket file descriptor
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset( & servaddr, 0, sizeof(servaddr));
  memset( & cliaddr, 0, sizeof(cliaddr));

  // Filling server information
  servaddr.sin_family = AF_INET; // IPv4
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);

  // Bind the socket with the server address
  if (bind(sockfd, (const struct sockaddr * ) & servaddr, sizeof(servaddr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  int len;
  int n, no;
  len = sizeof(cliaddr); //len is value/resuslt
  while (1) {
    n = recvfrom(sockfd, (char * ) buffer, MAXLINE,
      MSG_WAITALL, (struct sockaddr * ) & cliaddr, & len);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
    if (!strcmp(buffer, "halt"))
      exit(0);
    char buff2[50];
    int b1[20];
    strcpy(buff2, buffer);
    b1[1] = strlen(buff2);
    no = 0;
    for (int i = 0; i < b1[1]; i++)

      if (buff2[i] == 'a' || buff2[i] == 'e' || buff2[i] == 'i' || buff2[i] == 'o' || buff2[i] == 'u')
        no++;
    b1[2] = no;
    b1[0] = 1;
    for (int i = 0; i < b1[1] / 2; i++) {
      if (buff2[i] != buff2[b1[1] - i - 1]) {
        b1[0] = 0;
        break;
      }
    }
    //printf("\n%d%d%d",b1[0],b1[1],b1[2]);
    sendto(sockfd, (const char * ) & b1, sizeof(b1),
      MSG_CONFIRM, (const struct sockaddr * ) & cliaddr, len);
    // printf("Hello message sent.\n");
    if (!strcmp(buffer, "halt"))
      exit(0);
  }
  close(sockfd);
  return 0;
}
