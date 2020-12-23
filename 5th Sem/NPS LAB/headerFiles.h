//  "headerFiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>


// Common Declarations
int sd, newsd; // socket descriptor
int nr, ns; // Number of bytes recieved
char buffer[256]; // Input Buffer
struct sockaddr_in serverAddr;  //Server Address
int bindCode;
int length; // Length of the buffer

// Declarations for Server
struct sockaddr_in clientAddr; // Client Address
socklen_t clAddrLen; // Length of client Address

// Declarations for Client
//int ns; //Number of bytes to send
socklen_t slAddrLen;  // Length of socket Address