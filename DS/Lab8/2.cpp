//Program to concatenate two doubly linked list
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
};

class Doubly{
    public:
    Node *head, *tail;
    Doubly(){
        head=NULL;
        tail=NULL;
    }

    void append(int elem){
        Node *temp= new Node;
        temp->data=elem;
        temp->next=NULL;
        if(head==NULL){
            // list is empty
            head=temp;
            temp->prev=NULL;
        }
        else{
            temp->prev=tail;
            temp->prev->next=temp;
        }    
        tail=temp;
    }

    void display(){
        Node *trav= new Node;
        trav= head;
    while(trav!=NULL){
        cout<<trav->data<<' ';
        trav=trav->next;
    }
        cout<<endl;
    }

    void concatenate(Doubly d2){
        tail->next=d2.head;
        d2.head->prev=tail;
    }
};

int main(){
    Doubly d1, d2;
    d1.append(100);
    d1.append(1);
    d1.append(12);
    d2.append(1000);
    d2.append(201);
    d2.append(1112);
    d1.display();
    d2.display();
    d1.concatenate(d2);
    d1.display();
}