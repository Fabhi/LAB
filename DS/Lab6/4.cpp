//Program to convert a Prefix expression to an Infix expression
#include <iostream>
#include <algorithm>
using namespace std;
const int STACK_SIZE=100;
class Stack {
    private:
    int top;
    char arr[STACK_SIZE]={'\0'};
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

    char pop(){
        if(top>=0)
            return arr[top--];
        return -1;
    }

    char peek(){
        if(top>=0)
            return arr[top];
        else{
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};

class StackS{
    int top;
    string arr[100];
    public:
    StackS(){
        top=-1;
    }
    void push(string elem){
        if(top<STACK_SIZE){
            arr[++top]=elem;
        }
        else
            cout<<"Stack Overflow!";
    }

    string pop(){
        if(top>=0)
            return arr[top--];
        cout<<"Underflow!"<<endl;
    }
    string peek(){
        if(top>=0)
            return arr[top];
        cout<<"Underflow!"<<endl;
    }
};

string pretoInfix(string pre){
    StackS s;
    string output, final;
    reverse(pre.begin(),pre.end());
    int l=pre.length();
    for(int i=0;i<l;i++){
        if(isdigit(pre[i])||isalpha(pre[i])){
            s.push(string(1,pre[i]));
        }
        else{
            string a=s.pop();
            string b=s.pop();
            string exp='('+b+pre[i]+a+')';
            s.push(exp);
        }
    }
    output=s.peek();
    int len=output.length();
    for(int i=len-1;i>=0;i--){
        if(output[i]=='('){
            final+=')';}
        else if(output[i]==')'){
            final+='(';}
        else
        {
            final+=output[i];
        }
    }
    return final;
}

int getPriority(char c){
    switch (c)
    {
    case '-':
    case '+':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '$':
    case '^':
        return 3;
        break;
    default:
        return 0;
        break;
    }
}

string infixtoPostfix(string infix){
    infix='('+infix+')';
    int l=infix.size();
    string output;
    Stack s;
    for(int i=0;i<l;i++){
        if(isalpha(infix[i])||isdigit(infix[i]))
            output+=infix[i];
        else if(infix[i]=='(')
            s.push(infix[i]);
        else if(infix[i]==')'){
            while(s.peek()!='(')
                output+=s.pop();
            s.pop();
        }
        else{
            while(getPriority(infix[i])<=getPriority(s.peek()))
                output+=s.pop();
            s.push(infix[i]);
        }
    }
    return output;
}

int main(){
    string inp;
    cout<<"Enter the expression:";
    cin>>inp;
    cout<<infixtoPostfix(pretoInfix(inp));
}