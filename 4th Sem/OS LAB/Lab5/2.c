#include <stdio.h>
#include <sys/types.h>  //Contains data type such as pid_t
#include <sys/wait.h>  //Contains the wait system call
#include <unistd.h>  //Contains the API for POSIX system calls
#include <string.h>
int main(int argc, char ** argv){
    int i, j;
    int n=argc-1;
    char *temp;
    char **array;
    for(i=0;i<n;i++){
        strcpy(array[i],argv[i+1]);
    }
    int f = fork();
    if(f==0){
        printf(" |->Inside Child \n");
        
        for(i=0;i<n;i++){
            printf("%s",array[i]);
        }
        for(i=0;i<n;i++){
            for(j=1;j<n-i-1;j++){
                if(strcmp(array[j],array[j+1])){
                    strcpy(temp,array[j]);
                    strcpy(array[j],array[j+1]);
                    strcpy(array[j+1],temp);
                }
            }
            printf(" |->%s", array[i]);
        }
        return 1;
    }
    if(f>0){
        printf("Inside Parent \n");
        wait(NULL);
        for(i=1;i<argc;i++){
            printf("%s \n", argv[i]);
        }
    }
}