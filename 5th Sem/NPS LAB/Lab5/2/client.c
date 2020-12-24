#include "../../headerFiles.h"
int readIntoBuffer(char temp[]){
  memset(temp, '\0', sizeof(temp));
  fgets(temp, 256, stdin);
  temp[strcspn(temp, "\r\n")] = '\0';
  length = strlen(temp) * sizeof(char);
}
int main(){

    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
    printf("Socket Creation Error");
    exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(2220);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0){
    printf("Connection Error");
    exit(1);
    }

    printf("Connected\n");
    printf("Enter 1st string:");
    readIntoBuffer(buffer);
    if(send(sd, buffer, length, 0) < 0){
      printf("Sending Error ! \n");
      close(sd);
      exit(1);
    }

    printf("Enter 2nd string:");
    readIntoBuffer(buffer);
    if(send(sd, buffer, length, 0) < 0){
      printf("Sending Error ! \n");
      close(sd);
      exit(1);
    }

    memset(buffer,'\0', sizeof(buffer));
    if(recv(sd,buffer,sizeof(buffer), 0) < 0){
        printf("Recieving Error! \n");
        close(sd);
        exit(1);
    }
    printf("%s \n", buffer);

    while(1);
}
