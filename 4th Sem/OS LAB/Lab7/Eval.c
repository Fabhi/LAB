#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>  //Contains data type such as pid_t
#include <sys/wait.h>  //Contains the wait system call
#include <unistd.h>  //Contains the API for POSIX system calls
int main(int argc, char** argv){
    int pid = fork();
    if(pid==0){
        printf("Parent ID: %d \n", getppid());
        for(int i=1;i<argc;i++){
            if(atoi(argv[i])%2!=0)
                printf("%d ", atoi(argv[i]));
            }
        printf("\n");
        return 1;
    }
    else if(pid>0){
        wait(NULL);
        printf("Child ID: %d \n", pid);
        for(int i=1;i<argc;i++){
            if(atoi(argv[i])%2==0)
                printf("%d ", atoi(argv[i]));
        }
        printf("\n");
        return 1;
    }
    else
        printf("Fork Failed");
}

