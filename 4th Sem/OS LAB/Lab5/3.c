#include <stdio.h>
#include <sys/types.h>  //Contains data type such as pid_t
#include <sys/wait.h>   //Contains the wait system call
#include <unistd.h>     //Contains the API for POSIX system calls
#include <string.h>
int main(int argc, char** argv){
    int i, j;
    int fork1= fork();
    if(fork1==0){
        char* temp;
        printf("Sorted Array by child 1: ");
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
    else if(fork1>0){
        int fork2 = fork();
        if(fork2==0){
            char* key;  
            for (i=2; i < argc; i++) {  
                key = argv[i];  
                j = i-1;
                while (j >= 1 && strcmp(argv[j],key)>0){  
                    argv[j + 1] = argv[j];  
                    j = j - 1;  
                }  
                argv[j+1]=key;  
            }  
            printf("Sorted Array by child 2: ");
            for(i=1;i<argc;i++){
                printf("%s ", argv[i]);
            }
            printf("\n");
            return 1;
        }
        else if(fork2>0){
            // sleep(3);
            wait(NULL);
            printf("Original Array: ");
            for(i=1;i<argc;i++){
                printf("%s ", argv[i]);
            }
            printf("\n");
            return 1;
        }
        else
            printf("fork failed");
    }
}
