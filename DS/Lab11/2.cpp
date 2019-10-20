// Program to implement expression trees
#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int c){
        data=c;
        left=right=NULL;
    }
};

bool isoperator(char c){
    return c=='+'||c=='-'||c=='/'||c=='*';
}

Node* createTree(string postfix){
    stack<Node*> s;
    for (int i=0;i<postfix.length();i++){
        if (!isoperator(postfix[i])){
            Node *temp= new Node(postfix[i]);
            s.push(temp);
        }
        else{
            Node *temp= new Node(postfix[i]);
            temp->right=s.top();s.pop();
            temp->left=s.top();s.pop();
            s.push(temp);
        }
    }
    Node *temp= s.top();
    s.pop();
    return temp;
}

void infix(Node *root){
    if(root==NULL)
        return;
    infix(root->left);
    cout<<root->data<<" ";
    infix(root->right);
}
int operate(int a, int b, char c){
    switch(c){
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;
    }
}
int evaluate(Node *root){
    if(!isoperator(root->data)){
        return root->data;
    }
    else{
        int left=evaluate(root->left)-'0';
        int right=evaluate(root->right)-'0';
        int val= operate(left,right,root->data);
        root->data=val;
        return val;
    }
}
int main(){
    string s;
    cout<<"Enter a postfix expression";
    cin>>s;
    Node *root=createTree(s);
    infix(root);
    cout<<evaluate(root);
}