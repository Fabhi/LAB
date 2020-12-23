#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  int buffer[1024] = {0};

  int a,num;
  char *hello = "Hello from server";
  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  // Forcefully attaching socket to the port 8080
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );
  // Forcefully attaching socket to the port 8080
  if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0){
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  if (listen(server_fd, 3) < 0){
    perror("listen");
    exit(EXIT_FAILURE);
  }
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
    perror("accept");
    exit(EXIT_FAILURE);
  }
  valread = read( new_socket , hello, strlen(hello));
  valread = read( new_socket , &num, sizeof(num));
  printf("received num\n" );
  valread = read( new_socket , buffer, 1024);
  printf("received array\n" );
  int b,arr2[10],arr3[10],i,j,k;
  while(1){
    valread = read( new_socket , &a, sizeof(a));
    printf("\nReceieved choice.");
    switch(a)
    {
      case 1:
        printf("You chose 1");
        printf("\nEnter the element to be searched ");
        int key,found;
        scanf("%d", &key);

        for (i = 0; i < sizeof(buffer); i++){
          if (key == buffer[i] ){
            found = 1;
            break;
          }
        }
        if (found == 1)
        printf("\nElement is present in the array at position %d",i+1);
        else
        printf("\nElement is not present in the array\n");
        break;
      case 2:
        printf("You chose 2:");
        printf("1.Asscending 2. descending");
        scanf("%d",&b);
        if(b==1){
          int temp;
          for (j= 0; j < num; ++j){
            for (k= j + 1; k < num; ++k){
              if (buffer[j] > buffer[k]){
                temp = buffer[j];
                buffer[j] = buffer[k];
                buffer[k] = temp;
              }
            }
          }
          printf("The numbers arranged in ascending order are given below:\n");
          for (j = 0; j <num; ++j)
            printf("%d\n", buffer[j]);
        }
        else{
          int temp;
          for (j= 0; j < num; ++j){
            for (k= j + 1; k < num; ++k){
              if (buffer[j] < buffer[k]){
                temp = buffer[j];
                buffer[j] = buffer[k];
                buffer[k] = temp;
              }
            }
          }
          printf("The numbers arranged in descending order are given below:\n");
          for (j = 0; j <num; ++j)
            printf("%d\n", buffer[j]);
        }
        break;
      case 3:
        i=0;j=0,k=0;
        printf("You chose 3");
        for(i=0;i<num;i++){
          if (buffer[i]%2 == 0){
            arr2[j] = buffer[i];
            j++;
          }
          else{
            arr3[k] = buffer[i];
            k++;
          }
        }
        printf("\nThe Even elements are : \n");
        for(i=0;i<j;i++){
          printf("%d ",arr2[i]);
        }
        printf("\nThe Odd elements are :\n");
        for(i=0;i<k;i++){
          printf("%d ", arr3[i]);
        }
        printf("\n\n");
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid");
    }
  }

  send(new_socket , hello, strlen(hello) , 0 );
  return 0;
}
