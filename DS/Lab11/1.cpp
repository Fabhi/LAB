// Program to implememt a binary search tree
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int elem){
        data=elem;
        left=right=NULL;
    }
};

Node* insert(Node *node,int elem){
    if(node==NULL){
        return new Node(elem);       
    }
    if(elem>node->data){
        node->right=insert(node->right,elem);
    }
    else{
        node->left=insert(node->left,elem);
    }
    return node;
}

Node* search(Node *node, int elem){
    if(node==NULL||node->data==elem)
        return node;
    else if(node->data<elem){
        return search(node->right, elem);
    }
    else{
        return search(node->left,elem);
    }
}

void inorder(Node *root) 
{ 
    if(!root) 
        return;
    inorder(root->left); 
    cout<<root->data<<" "; 
    inorder(root->right); 
}

Node* deleteNode(Node* node, int elem){
    if(node==NULL)
        return node;
    if(elem>node->data)
        node->right=deleteNode(node->right,elem);
    else if(elem<node->data)
        node->left=deleteNode(node->left,elem);
    else{
        if(node->left==NULL){
            Node *temp=node->right;
            delete node;
            return temp;
        }
        else if(node->right==NULL){
            Node* temp= node->left;
            delete node;
            return temp;
        }
        else{
            // Both children exist
            Node *temp=node;
            while(temp && temp->left){
                temp=temp->left;
            }
            node->data=temp->data;
            node->right=deleteNode(node->right, temp->data);
        }
    }
}


int main(){
    Node *root=NULL;
    root=insert(root,30);
    insert(root,300);
    insert(root,10);
    insert(root,200);
    insert(root,800);
    insert(root,400);
    inorder(root);
    search(root,120)?cout<<"Yes":cout<<"NO";
}