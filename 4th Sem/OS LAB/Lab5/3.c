#include <stdio.h>
#include <sys/types.h>  //Contains data type such as pid_t
#include <sys/wait.h>   //Contains the wait system call
#include <unistd.h>     //Contains the API for POSIX system calls
#include <string.h>
int main(int argc, char** argv){
    int i, j;
    char temp[100];
    int fork1= fork();
    if(fork1==0){
        printf("Sorted Array by child 1: ");
        for(i=1;i<argc;i++){
            for(j=1;j<argc-i;j++){
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
    else if(fork1>0){
        int fork2 = fork();
        if(fork2==0){
            char key[100];  
            for (i=2; i < argc; i++) {  
                strcpy(key,argv[i]);  
                j = i-1;
                while (j >= 1 && strcmp(argv[j],key)>0){  
                    strcpy(argv[j + 1], argv[j]);  
                    j = j - 1;  
                }  
                strcpy(argv[j+1],key);  
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