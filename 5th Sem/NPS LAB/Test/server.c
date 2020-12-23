#include "../headerFiles.h"

void readIntoBuffer(void){
  memset(buffer, '\0', sizeof(buffer));
  fgets(buffer, 256, stdin);
  buffer[strcspn(buffer, "\r\n")] = '\0';
  length = strlen(buffer) * sizeof(char);
}

int main(){
  if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    printf("Socket Creation Error");
    exit(1);
  }
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(22222);
  serverAddr.sin_addr.s_addr = inet_addr(INADDR_ANY);

  if(bind(sd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0){
    printf("Binding Error");
    close(sd);
    exit(1);
  }

  if(listen(sd, 1) < 0){
    printf("Listening Error");
    close(sd);
    exit(1);
  }

  printf("Listening...\n");

  if((newsd=accept(sd, (struct sockaddr*) &clientAddr, sizeof(clientAddr)))<0){
    printf("Accepting Error");
    close(sd);
    exit(1);
  }

  while(1){
    //Clear the buffer
    memset(buffer, '\0', sizeof(buffer));

    // Recieve from the connected client
    if( recv(newsd,buffer,sizeof(buffer),0) < 0){
      printf("Recieving Error! \n");
      close(newsd);
      exit(1);
    }

    // if client terminates, terminate server too
    if(strcmp(buffer,"stop") == 0){
      close(newsd);
      exit(0);
    }

    // Display the recieved string
    printf("Received string : %s", &buffer);

    readIntoBuffer();
    if(send(newsd, buffer, length, 0) < 0){
      printf("Sending Error ! \n");
      close(newsd);
      exit(1);
    }

    // Check for terminating server
    if(strcmp(buffer,"stop") == 0){
      close(newsd);
      exit(0);
    }
  }
}
