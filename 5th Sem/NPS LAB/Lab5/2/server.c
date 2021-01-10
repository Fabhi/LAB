
#include "../../headerFiles.h"
#include <time.h>
int clients = 0;
char buffer2[256];

char anagrams(){
    int i, j;
    int n  = strlen(buffer);
    int n1 = strlen(buffer2);
    char temp;
   // If both strings are of different length, then they are not anagrams
   if( n != n1) {
      return 'N';
   }
   //Sorting
   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (buffer[i] > buffer[j]) {
            temp  = buffer[i];
            buffer[i] = buffer[j];
            buffer[j] = temp;
         }
         if (buffer2[i] > buffer2[j]) {
            temp  = buffer2[i];
            buffer2[i] = buffer2[j];
            buffer2[j] = temp;
         }
      }
   }
   for(i = 0; i<n; i++) {
      if(buffer[i] != buffer2[i]) {
         return 'N';
      }
   }
   return 'Y';
}

int main(){
  if((sd = socket(PF_INET, SOCK_STREAM, 0)) < 0){
    printf("Socket Creation Error");
    exit(1);
  }

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(2220);
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
        char* ip = inet_ntoa(clientAddr.sin_addr);
        int port = ntohs(clientAddr.sin_port);

        printf("Socket address of client %d: %s:%d\n", ++clients, ip, port);
        time_t now;
        time(&now);
        printf("Connected at %s", ctime(&now));

        memset(buffer,'\0', sizeof(buffer));
        if(recv(newsd,buffer,sizeof(buffer), 0) < 0){
            printf("Recieving Error! \n");
            close(newsd);
            exit(1);
        }

        memset(buffer2,'\0', sizeof(buffer2));
        if(recv(newsd,buffer2,sizeof(buffer2), 0) < 0){
            printf("Recieving Error! \n");
            close(newsd);
            exit(1);
        }

        printf("Received string from Client : %s %s\n", buffer, buffer2);

        char ret = anagrams();
        if(ret == 'Y')
            strcpy(buffer, "Strings are anagrams");
        else
            strcpy(buffer,"Strings are not anagrams");
        length = strlen(buffer) * sizeof(char);
        if(send(newsd, buffer, length, 0) < 0){
            printf("Sending Error ! \n");
            close(newsd);
            exit(1);
        }
        close(newsd);
    }
    close(sd);
}
