#include <iostream>
#include <string.h>
#include <stdio.h>
#define STACK_SIZE 10
using namespace std;
class Stack {
    private:
    int top;
    char arr[STACK_SIZE];
    public:
    Stack(){
        top=-1;
    }
    void push(int elem){
        if(top<STACK_SIZE){
            arr[++top]=elem;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }

    int pop(){
        if(top>=0)
            return arr[top--];
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }

    int peek(){
        if(top>=0)
            return arr[top];
        else{
            cout<<"Underflow"<<endl;
            return -1;
        }
    }

    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
};

int main(){
    Stack stk1,stk2;
    char a[50];
    gets(a);
    int n=strlen(a);
    for(int i=n-1;i>=0;i--){
        stk1.push(a[i]);
    stk1.display();
    stk2.display();
    

    bool b=true;
    for(int i=0;i<n;i++){
        if(stk1.=stk2.pop()){
            b=false;
            break;
        }
        
    }
    if(b){
        cout<<"String is a palindrome.";
    }
    else{
        cout<<"String is not a palindrome";
    }
    return 0;

}