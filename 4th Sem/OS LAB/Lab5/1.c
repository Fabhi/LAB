#include <stdio.h>
#include <sys/types.h>  //Contains data type such as pid_t
#include <sys/wait.h>  //Contains the wait system call
#include <unistd.h>  //Contains the API for POSIX system calls
int main(){
    pid_t pid;
    if(fork()==0){
        printf(" |-> Inside child \n");
        printf(" |-> Pid of child: %d \n", getpid());
        printf(" |-> PPid of child: %d \n", getppid());
        printf(" |-> Child Terminated \n\n");
        return 1;
    }
    else if(fork>0){
        printf("Inside parent \n");
        pid = wait(NULL);
        printf("Pid of Parent: %d \n", getpid());
        printf("PPid of Parent: %d \n", getppid());
        printf("Parent Terminated \n");
    }
    else
    {
        printf("Fork Failed");
    }
}


