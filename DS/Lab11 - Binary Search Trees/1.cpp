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
    if(node==NULL)
        return new Node(elem);       
    if(elem>node->data)
        node->right=insert(node->right,elem);
    else
        node->left=insert(node->left,elem);
    return node;
}


Node* search(Node *node, int elem){
    if(node==NULL||node->data==elem)
        return node;
    else if(node->data<elem)
        return search(node->right, elem);
    else
        return search(node->left,elem);
}

void inorder(Node *root){ 
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
    int n, choice;
    cout<<"1. Insert an element "<<endl;
    cout<<"2. Delete an element "<<endl;
    cout<<"3. Search an element "<<endl;
    cout<<"4. Print the array "<<endl;
    while(true){
        cout<<">";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element:";
                cin>>n;
                insert(root,n);
                break;
            case 2:
                cout<<"Enter element:";
                cin>>n;
                deleteNode(root,n);
                break;
            case 3:     
                cout<<"Enter element:";
                cin>>n;
                search(root,n)?cout<<"Yes"<<endl:cout<<"NO"<<endl;
                break;
            case 4:
                inorder(root);
                cout<<endl; 
                break;
            default:
                cout<<"Invalid Choice!"<<endl;
        }
    }
}