// Program to check if two binary trees are mirror images of each other using recursive checking
#include <iostream>
using namespace std;

struct Node{
    Node *lc, *rc;
    int data;
};

class Tree{
    private:
    Node *root;
    public:

    Tree(int arr[],int n){
        root= insertLevelOrder(arr,root,0,n);
    }

    Node* newNode(int elem){
        Node *node= new Node();
        node->data=elem;
        node->lc=node->rc=NULL;
        return node;
    }

    Node* insertLevelOrder(int arr[],Node* root, int i, int n){
        if (i < n){ 
            Node* temp = newNode(arr[i]); 
            root = temp;  
            root->lc = insertLevelOrder(arr, 
                    root->lc, 2 * i + 1, n); 
            root->rc = insertLevelOrder(arr, 
                    root->rc, 2 * i + 2, n); 
        } 
        return root; 
    }

    int Mirror(Node* a, Node* b) {
        if (!a && !b) 
            return true;  
        if (!a || !b) 
            return false; 
        return  a->data == b->data && Mirror(a->lc, b->rc) && Mirror(a->rc, b->lc); 
    }

    bool isMirror(Tree t2){
        return Mirror(root, t2.root);
    } 
};

int main(){
    int arr1[]={2,3,4};
    int arr2[]={2,4,3};
    Tree t1(arr1,3);
    Tree t2(arr2,3);
    t1.isMirror(t2)?cout<<"Yes":cout<<"No";
    return 0;
}