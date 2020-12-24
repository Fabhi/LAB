#include "../../headerFiles.h"
int clients = 0;

void writeToFile(){
    FILE *fp;
    fp = fopen("sample.txt", "a+");
    fprintf(fp, "%s ", buffer);
    fclose(fp);
}

int main(){
  if((sd = socket(PF_INET, SOCK_STREAM, 0)) < 0){
    printf("Socket Creation Error");
    exit(1);
  }

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(2226);
  serverAddr.sin_addr.s_addr = htons(INADDR_ANY);

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

  printf("\n\n\n\nListening...\n");

  while(1){
      if((newsd=accept(sd, (struct sockaddr*) &clientAddr, &clAddrLen))<0){
          printf("Accepting Error");
          close(sd);
          exit(1);
      }
      pid_t pid;
      if(( pid = fork() ) == 0){ //Child Process
          if( recv(newsd,buffer,sizeof(buffer), 0) < 0){
            printf("Recieving Error! \n");
            close(newsd);
            exit(1);
          }
          printf("Received string from Client : %s\n", buffer);

          char* ip = inet_ntoa(clientAddr.sin_addr);
          int port = ntohs(clientAddr.sin_port);

          printf("Socket address : %s:%d\n", ip, port);
          close(newsd);
          writeToFile();
          exit(0);
      }
      else{ //Parent
          if(++clients > 2){
              printf("More than 2 clients connected. Terminating ...");
              close(sd);
              exit(0);
          }
          continue;
      }
  }
}
