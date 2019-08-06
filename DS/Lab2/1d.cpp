#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
    char a[50],b[50];
    int sa,sb;
    cout<<"Enter Primary String:";
    cin>>a;
    fflush(stdin);
    cout<<"Enter Sub-string:";
    cin>>b;
    for (sa=0;a[sa]!='\0';sa++);
    for (sb=0;b[sb]!='\0';sb++);
    int loc;
    cout<<"\nEnter location to put sub-string";
    cin>>loc;
    for(int i = loc; i < sa; i++){
        a[i + sb] = a[i];
        }
    
    for(int i = 0; i < sb; i++){
        a[loc + i] = b[i];
        }
    b[sb + 1] = '\0';
    printf("After inserting the string is %s", a);
}