#include <iostream>
using namespace std;
int main(){
    char a[50],b[50];
    int i;
    cout<<"Enter Primary String:";
    cin>>a;
    cout<<"Enter Sub-string :";
    cin>>b;
    for (i=0;b[i]!='\0';i++);
    int loc;
    cout<<"Enter location to put sub-string";
    cin>>loc;
    for(int j=loc;j<loc+i;j++){
        a[j+i]=a[j];
        a[j]=b[j];
    }
    cout<<a;
}