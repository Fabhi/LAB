#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define STACK_SIZE 100
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
    Stack stk1;
    char a[50];
    cout<<"Enter String:";
    gets(a);
    int n=strlen(a);
    for(int i=0;i<n;i++){
        stk1.push(a[i]);}
    int i;
    for(i=0;(i<n)&&(stk1.pop()==a[i]);++i){}
    if(i==n){
        cout<<"String is a palindrome.";
    }
    else{
        cout<<"String is not a palindrome.";
    }

}