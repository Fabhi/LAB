#include "../../headerFiles.h"
char user[256], pass[256];
void readIntoBuffer(void){
  memset(buffer, '\0', sizeof(buffer));
  fgets(buffer, 256, stdin);
  buffer[strcspn(buffer, "\r\n")] = '\0';
  length = strlen(buffer) * sizeof(char);
}

int main(){
  if((sd = socket(PF_INET, SOCK_STREAM, 0)) < 0){
    printf("Socket Creation Error");
    exit(1);
  }
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(22224);
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

  printf("Listening...\n");
  clAddrLen =  sizeof(clientAddr);
  if((newsd=accept(sd, (struct sockaddr*) &clientAddr, &clAddrLen))<0){
    printf("Accepting Error");
    close(sd);
    exit(1);
  }

  while(1){
    //Clear the username buffer
    memset(user, '\0', sizeof(user));

    // Recieve from the connected client
    if( recv(newsd,user,sizeof(user),0) < 0){
      printf("Recieving Error! \n");
      close(newsd);
      exit(1);
    }
    printf("Received string : %s \n", user);
    //Clear the password buffer
    memset(pass, '\0', sizeof(pass));

    // Recieve from the connected client
    if( recv(newsd,pass,sizeof(pass),0) < 0){
      printf("Recieving Error! \n");
      close(newsd);
      exit(1);
    }
    printf("Received string : %s \n", pass);

    //Open the file and check creds
    FILE *fp, *fp2, *fp3;
    if ((fp = fopen("creds.txt", "r")) == NULL) {
        printf("\nFile not found");
        close(newsd);
        exit(1);
    }
    printf("Here\n");
    char temp[512];
    int flag =0 ;
    while (fgets(temp, 512, fp) != NULL) {
        if ((strstr(temp, user)) != NULL) {
          //match for password
          flag= 1;
          fp2 = fp+sizeof(char);
          while (fgets(temp, 512, fp2) != NULL){
                if ((strstr(temp, pass)) != NULL){
                    //return creds
                    flag =2;
                    fp3 = fp2+sizeof(char);
                    while (fgets(temp, 512, fp2) != NULL){
                        if ((strstr(temp, "\n")) != NULL){
                            strcpy(buffer, temp);
                            break;
                        }
                    }
                }
            }
        }
    }
    memset(buffer, '\0', sizeof(buffer));
    if(flag==0)
    strcpy(buffer, "Incorrect Username");
    else if(flag==1)
    strcpy(buffer, "Incorrect Password");
    else if(flag == 2)
    strcpy(buffer,"12121");
    if(send(newsd, buffer, length, 0) < 0){
      printf("Sending Error ! \n");
      close(newsd);
      exit(1);
    }
  }
}
