// Program to copy one tree to another
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *lc, *rc;
};

class Tree{
    private:
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
    public:

    Tree(){
        root=NULL;
    }

    void create(){
        root=createTree();
    }

    void post(Node *node) const{
        if (node == NULL) 
            return;  
        post(node->lc);
        post(node->rc);
        cout<<node->data <<" "; 
    }
    void PostOrder() const{
        cout<<"Postorder Traversal >>";
        post(root);
        cout<<endl;
    }

    // This function employs operator overriding to copy a tree
    void copy(Node *dst, Node *src){
        dst->data=src->data;
        if(src->lc){
            Node *left=new Node;
            dst->lc=left;
            copy(left, src->lc);
        }
        else{
            dst->lc=NULL;
        }
        if(src->rc){
            Node *right=new Node;
            dst->rc=right;
            copy(right, src->rc);
        }
        else{
            dst->rc=NULL;
        }
        return;
    }

    void operator=(Tree t2){
        root=new Node;
        copy(root,t2.root);
    }
};

int main(){
    Tree t1,t2;
    t1.create();
    t1.PostOrder();
    t2=t1;
    t2.PostOrder();
}