// Program to create a banking application
#include <stdio.h>
#include <conio.h>

char name[11][3]={"AB","BC","CD","DE","EF","GH","HI","JK","KL","MN",'\0'};
char pass[11][3]={"AB","BC","CD","DE","EF","GH","HI","JK","KL","MN",'\0'};
int  acc[11]= {00,11,22,33,44,55,66,77,88,99,'\0'};

int main(){
    char pasword[10], usrname[10], ch1;
    int numb, i=0, flag, tries=0,j;

    printf("Enter Account Number: ");
    scanf("%d", &numb);
        for(j=0;j<11;j++){
            if (numb==acc[j]){
                printf("Enter the password");
                flag=1;
                while(flag){
                    ch1 = getch();
                    pasword[i] = ch1;
                    if(ch1=='\r')   {flag=0;}
                    printf("%c",'*');
                    i++;  }

                if(pasword==pass[j]){
                    printf("Entry Granted\n");}
                else{
                    printf("Denied\n");
                    tries+=1;
                }    
                }
                if(tries==3){
                    return 0;
                }
                }
}