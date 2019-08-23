#include <iostream>
#include <string.h>
#include <stdio.h>
#define STACK_SIZE 100
char open[]={'{','[','('};
char close[]={'}',']',')'};
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
    Stack para;
    char ch[50];
    gets(ch);
    int n=strlen(ch);
    for(int i=0;i<n;i++){
        para.push(ch[i]);
        if (para.peek()==ch[i]){
            para.pop();
        }
    }
    if(ch[])

}