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
int length; // Length of the buffer
char buffer[256]; // Input Buffer
struct sockaddr_in serverAddr, clientAddr;  //Server Address
socklen_t clAddrLen = sizeof(struct sockaddr_in); // Length of client Address
socklen_t slAddrLen = sizeof(struct sockaddr_in);  // Length of socket Address
