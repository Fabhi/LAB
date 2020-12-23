//  "headerFiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


// Common Declarations
int sd, newsd; // socket descriptor
int nr, ns; // Number of bytes recieved
char buffer[256]; // Input Buffer
struct sockaddr_in serverAddr;  //Server Address
int bindCode;
int length; // Length of the buffer

// Declarations for Server
struct sockaddr_in clientAddr; // Client Address
int clAddrLen; // Length of client Address

// Declarations for Client
//int ns; //Number of bytes to send
int slAddrLen;  // Length of socket Address
