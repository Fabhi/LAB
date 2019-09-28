//Program to implement Binary Tree
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node *lc, *rc;
};

class Tree{

    public:
    Node *root;

    protected:
    Node* createTree(){
        int val;
        cout<<">";
        cin>>val;
        if(val==-1)
            return NULL;
        Node *temp= new Node;
        temp->data=val;   
        cout<<"Left child of "<<val<<endl;
        temp->lc=createTree();
        cout<<"Right child of "<<val<<endl;
        temp->rc=createTree();
    }

    void post(Node *node) const{
        if (node == NULL) 
            return;  
        post(node->lc);
        post(node->rc);
        cout<<node->data <<" "; 
    }

    void pre(Node *node) const{
        if(node == NULL)
            return;
        cout<<node->data <<" ";
        pre(node->lc);
        pre(node->rc);
    }

    void in(Node *node) const{
        if(node == NULL)
            return;
        in(node->lc);
        cout<<node->data <<" ";
        in(node->rc);
    }

    public:
    Tree(){
        root=NULL;
    }

    void create(){
        cout<<"Use -1 to break"<<endl;
        cout<<"Enter root"<<endl;
        root=createTree();
    }

    void postOrder() const{
        cout<<"Postorder Traversal >>";
        post(root);
        cout<<endl;
    }

    void preOrder() const{
        cout<<"Preorder Traversal >>";
        pre(root);
        cout<<endl;
    }

    void inOrder() const{
        cout<<"Inorder Traversal >>";
        in(root);
        cout<<endl;
    }

    void levelOrder() const{
        cout<<"Levelorder Traversal >>";
        queue <Node*> q;
        q.push(root);
        Node *curr;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            cout<<curr->data<<' ';
            if(curr->lc!=NULL){
                q.push(curr->lc);
            }
            if(curr->rc!=NULL){
                q.push(curr->rc);
            }
        }
        cout<<endl;
    }

    void iterativePreorder(){
        cout<<"Iterative Preorder Traversal >>";
        if(root==NULL) 
            return;
        stack <Node*> S;
        Node *curr= root;
        S.push(curr);
        while(!S.empty()){
            curr=S.top();
            S.pop();
            cout<<curr->data<<' ';
            if(curr->rc)
                S.push(curr->rc);
            if(curr->lc)
                S.push(curr->lc);
        }
        cout<<endl;
    }

    void iterativePostorder(){
        cout<<"Iterative Postorder Traversal >>";
        if(root==NULL)
            return;
        stack <Node*> S;
        Node *curr=root;
        do{
            while(curr){
                if(curr->rc)
                    S.push(curr->rc);
                S.push(curr);
                curr=curr->lc;
            }

            curr=S.top();
            S.pop();

            if(curr->rc && S.top()==curr->rc){
                S.pop();
                S.push(curr);
                curr=curr->rc;
            }
            else{
                cout<<curr->data<<' ';
                curr= NULL;
            }            
        }while(!S.empty());
        cout<<endl;
    }
};

int main(){
    Tree T;
    T.create();
    T.inOrder();
    T.preOrder();
    T.postOrder();
    T.levelOrder();
    T.iterativePreorder();
    T.iterativePostorder();
}