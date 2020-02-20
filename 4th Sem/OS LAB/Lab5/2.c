#include <stdio.h>
#include <sys/types.h>  //Contains data type such as pid_t
#include <sys/wait.h>   //Contains the wait system call
#include <unistd.h>     //Contains the API for POSIX system calls
#include <string.h>
int main(int argc, char** argv){
    int i, j;
    char temp[100];
    if(fork()==0){
        printf("Sorted Array: ");
        for(i=1;i<argc;i++){
            for(j=1;j<argc-i-1;j++){
                if(strcmp(argv[j],argv[j+1])>0){
                    strcpy(temp,argv[j]);
                    strcpy(argv[j],argv[j+1]);
                    strcpy(argv[j+1],temp);
                }
            }
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
