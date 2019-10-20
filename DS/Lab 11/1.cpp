// Program to implement a BST
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

class Node{
    public:
    Node *left, *right;
    int data; 
};

Node* insert(Node* root, int elem){
    if(!root){
        Node *trav=new Node;
        trav->data=elem;
        trav->left=trav->right=NULL;
        return trav;
    }
    if(elem>root->data)
        root->right=insert(root->right, elem);
    else
        root->left=insert(root->left, elem);
    return root;
}

void inorder(Node *root){
    //cout << "Inorder Test" << endl;
    if(!root)
        return;
    inorder(root->left);
    cout<<(char) root->data<<endl;
    inorder(root->right);
}

void remove(Node *root, int elem){
    // Process: Traverse inorder. Replacement is always the inorder successor(at the right hand)
    
}

void levelOrder(Node* root) {
        cout<<"Levelorder Traversal >>";
        queue <Node*> q;
        q.push(root);
        Node *curr;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            cout<<curr->data<<' ';
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        cout<<endl;
    }

Node* postTree(string post){
    stack<Node*> s;
    for(int i=0;i<post.length();i++){
        Node* newNode = new Node;
        switch(post[i]){
            case '+':
            case '-':
            case '*':
            case '/':
                //Node* newNode = new Node;
                newNode->data = post[i];
                newNode->right = s.top();
                s.pop();
                newNode->left = s.top();
                s.pop();
                s.push(newNode);
                break;
            default:
                //Node* newNode = new Node;
                newNode->data = post[i];
                newNode->left = newNode->right = NULL;
                s.push(newNode);
                break;
        }
    }
    
    return s.top();
}

int evalTree(Node* root){
    if(root->left == root->right == NULL){
        return (int) root->data;
    }
    if (root->data == (int) '+'){
        return evalTree()
    }
}

int main(){
    Node *root= NULL;
    root=insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,6);
    insert(root,7);
    insert(root,8);
    inorder(root);
    
    inorder(postTree("52+"));
    return 0;
}