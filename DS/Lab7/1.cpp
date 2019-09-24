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
    int count=0;
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
        node *trav=new node;
        node *temp=new node;
        
        int var;
        while(trav!=NULL){
            while(temp!=NULL){
                if(temp->data>temp->next->data){
                    cout<<"in"<<endl;
                    var=temp->data;
                    temp->data=temp->next->data;
                    temp->next->data=var;
                }
            temp=temp->next;
            }
        trav=trav->next;
        }
        head=trav;
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
}