#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080
int main(int argc, char const *argv[]){
  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  int a[10],num;
  char buffer[1024] = {0};
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    printf("\n Socket creation error \n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  // Convert IPv4 and IPv6 addresses from text to binary form
  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))< 0){
    printf("\nConnection Failed \n");
    return -1;
  }
  printf("Enter num of elements:\n");
  scanf("%d",&num);
  send(sock , &num , sizeof(num) , 0 );
  printf("num sent\n");
  printf("Enter elements:\n");
  int i;
  for(i=0;i<num;i++)
  scanf("%d",&a[i]);
  send(sock , a , sizeof(a) , 0 );
  printf("Array sent\n");
  int ch;
  do{
  printf("Enter choice: 1:search 2:sort 3:split 4:exit\n");
  scanf("%d",&ch);
  send(sock , &ch , sizeof(ch) , 0 );
  printf("choice sent\n");}
  while(ch!=4);

  valread = read( sock , buffer, 1024);
  printf("%s\n",buffer );
  return 0;
}
