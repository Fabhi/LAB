//Program to implement linked list opeartion without tail
#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class LinkedList{
    private:
    node *head, *tail;
    public:

    LinkedList(){
        head=NULL;
        tail=NULL;
    }

    void append(int elem){
        node *temp= new node;
        temp->data=elem;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        node *trav=new node;
        trav=tail;
        trav->next=temp;
        tail=temp;
    }

    void insert_after(int elem, int value){
        node *temp=new node;
        temp->data=elem;
        node *trav=new node;
        trav=head;
        bool t=true;
        while(trav!=NULL){
            if(trav->data==value){
                temp->next=trav->next;
                trav->next=temp;
                t=false;
                break;
            }
            trav=trav->next;
        }
        if(t){
            cout<<"Element not found!"<<endl;
        }
    }

    void insert_before(int elem, int value){
        node *temp= new node;
        temp->data=elem;
        node *trav=new node;
        trav=head;
        bool t=true;
        while(trav!=NULL){
            if(trav->next->data==value){
                temp->next=trav->next;
                trav->next=temp;
                t=false;
                break;
            }
            trav=trav->next;
        }
        if(t){
            cout<<"Element not found"<<endl;
        }
    }

    void remove(int elem){
        if (head==NULL){
            cout<<"Empty list!"<<endl;
            return;
        }
        node *trav= new node;
        trav=head;
        bool b=true;
        if(trav->data==elem){
            head=trav->next;
            b=false;
            return;
        }
        while(trav!=NULL){
            if(trav->next->data==elem){
                trav->next=trav->next->next;
                b=false;
                break;
            }
            trav=trav->next;
        }
        if(b){
            cout<<"Element not found in the list";
        }
    }

    void traverse(){
        node *trav= new node;
        trav=head;
        while(trav!=NULL){
            cout<<trav->data<<' ';
            trav=trav->next;
        }
        cout<<endl;
    }

    void reverse(){
        node *prev=NULL, *next=NULL, *curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    } 

    void sort(bool rev=false){
        node *t= new node;
        int temp;
        node *t2= new node;
        t=head;
        while(t->next!=NULL){
            t2=t->next;
            while(t2!=NULL){
                if(t->data>t2->data){
                    temp=t->data;
                    t->data=t2->data;
                    t2->data=temp;
                }
                t2=t2->next;
            }
            t=t->next;
        }
    if(rev)
        reverse();
    }

    void delete_alternate(){
        node *temp= new node;
        node *temp2= new node;
        temp=head;
        temp2=temp->next;
        while(temp2!=NULL&&temp!=NULL){
            temp->next=temp2->next;
            delete temp2;
            temp=temp->next;
            if(temp!=NULL)
                temp2=temp->next;
        }
        
    }

    void insert_sort(int elem){
        node *temp=new node;
        node *trav=new node;
        temp->data=elem;
        temp->next=NULL;
        trav=head;
        if(trav->data>elem){
            temp->next=head;
            head=temp;
            return;
        }
        while(trav->next!=NULL){
            if(trav->next->data>elem){
                temp->next=trav->next;
                trav->next=temp;
                break;
            }
            trav=trav->next;
        }
        if(trav->next==NULL){
            trav->next=temp;
        }
    } 
};
int main(){
    LinkedList l;
    l.append(10);
    l.append(100);
    l.append(200);
    l.append(300);
    l.append(400);
    l.traverse();
    l.insert_after(8000,400);
    l.insert_before(800,100);
    l.traverse();
    l.remove(100);
    l.reverse();
    l.traverse();
    l.sort();
    l.traverse();
    l.delete_alternate();
    l.traverse();
    l.insert_sort(8);
    l.traverse();
}