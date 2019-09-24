//Program to implement Doubly Linked List

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next, *prev;
};

class Doubly{
    private:
    Node *head, *tail;
    public:
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

    void delete_end(){
        Node *temp= new Node;
        temp=tail;
        temp->prev->next=NULL;
        tail=temp->prev;
        delete temp;
    }

    void insert_pos(int elem, int loc){
        Node *temp= new Node;
        Node *trav= new Node;
        temp->data=elem;
        trav=head;
        int count=0;
        while(trav!=NULL){
            if(count==loc){
                break;
            }
            count++;
            trav=trav->next;            
        }
        if(trav==NULL){
            append(elem);
            return;
        }
        trav->prev->next=temp;
        temp->prev=trav->prev;
        temp->next=trav;
        trav->prev=temp;
    }

    void delete_pos(int loc){
        Node *trav;
        trav=head;
        int count=0;
        while(trav!=NULL){
            if(count==loc){
                break;
            }
            count++;
            trav=trav->next;            
        }
        if(trav==NULL){
            delete_end();
        }
        trav->prev->next=trav->next;
        trav->next->prev=trav->prev;
    }

    void insert_after(int elem, int val){
        Node *temp= new Node;
        Node *trav= new Node;
        temp->data=elem;
        trav=head;
        bool found=false;
        while(trav!=NULL){
            if(val==trav->data){
                found=true;
                if(trav->next!=NULL)
                    trav->next->prev=temp;
                else
                    tail=temp;
                temp->next=trav->next;
                trav->next=temp;
                temp->prev=trav;
                break;
            }
            trav=trav->next;
        }
        if(!found){
            cout<<"Element not found"<<endl;
        }
    }

    void insert_before(int elem, int val){
        Node *temp= new Node;
        Node *trav= new Node;
        temp->data=elem;
        trav=tail;
        bool found=false;
        while(trav!=NULL){
            if(val==trav->data){
                found=true;
                if(trav->prev!=NULL)
                    trav->prev->next=temp;
                else
                    head=temp;
                temp->prev=trav->prev;
                trav->prev=temp;
                temp->next=trav;
                break;
            }
            trav=trav->prev;
        }
        if(!found){
            cout<<"Element not found"<<endl;
        }
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

    void reverse(){
        Node *temp;
        Node *trav= new Node;
        trav=head;
        while(trav!=NULL){
            temp=trav->next;
            trav->next=trav->prev;
            trav->prev=temp;
            trav=trav->prev;
        }
        temp=head;
        head=tail;
        tail=temp;
    }
};

int main(){
    Doubly d;
    d.append(19);
    d.display();
    d.append(20);
    d.display();
    d.insert_pos(21,1);
    d.display();
    d.insert_after(23,20);
    d.insert_before(24,20);
    d.display();
    d.reverse();
    d.display();
    d.delete_end();
    d.delete_pos(1);
    d.display();
}