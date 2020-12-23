#include "../headerFiles.h"


int readIntoBuffer(void){
  memset(buffer, '\0', sizeof(buffer));
  fgets(buffer, 256, stdin);
  buffer[strcspn(buffer, "\r\n")] = '\0';
  length = strlen(buffer) * sizeof(char);
}
int main(){

  if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
    printf("Socket Creation Error");
    exit(1);
  }

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(22223);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if(connect(sd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0){
    printf("Connection Error");
    exit(1);
  }

  while(1){
    // Ask for input
    printf("Enter the string: ");
    readIntoBuffer();

    if(send(sd, buffer, length, 0) < 0){
      printf("Sending Error ! \n");
      close(sd);
      exit(1);
    }
    if(strcmp(buffer,"stop") == 0){
      close(sd);
      exit(0);
    }

    memset(buffer, '\0', sizeof(buffer));

    if(recv(sd,buffer,sizeof(buffer),0)< 0){
      printf("Recieving Error! \n");
      close(sd);
      exit(1);
    }

    printf("Received String : %s\n",buffer);

  }
}
