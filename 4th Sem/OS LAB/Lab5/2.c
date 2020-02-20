#include <stdio.h>
#include <sys/types.h>  //Contains data type such as pid_t
#include <sys/wait.h>   //Contains the wait system call
#include <unistd.h>     //Contains the API for POSIX system calls
#include <string.h>
int main(int argc, char** argv){
    int i, j;    
    if(fork()==0){
        char* temp;
        printf("Sorted Array: ");
        for(i=1;i<argc;i++){
            for(j=1;j<argc-i;j++){
                if(strcmp(argv[j],argv[j+1])>0){
                    temp = argv[j];
                    argv[j] = argv[j+1];
                    argv[j+1] = temp;
                }
            }

        }
        for(i=1;i<argc;i++){
            printf("%s ", argv[i]);
        }
        printf("\n");
        return 1;
    }
    if(fork()>0){
        wait(NULL);
        printf("Original Array: ");
        for(i=1;i<argc;i++){
            printf("%s ", argv[i]);
        }
        printf("\n");
        return 1;
    }
}
