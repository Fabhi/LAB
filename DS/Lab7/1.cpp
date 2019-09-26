//Menu Driven Singly Linked List Program
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
        //EDGE CASE:Element is at head
        if(trav->data==value){
            head=temp;
            temp->next=trav;
            return;
        }
        while(trav->next!=NULL){
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
        // EDGE CASE:ELement at head
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
        //EDGE CASE:List Empty
        if(head==NULL){
            append(elem);
            return;
        }
        // EDGE CASE:Element at head
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
        // EDGE CASE: Element at Tail
        if(trav->next==NULL){
            trav->next=temp;
        }
    } 
};
int main(){
    LinkedList L;
    //MENU DRIVEN PROGRAM TO IMPLEMENT THE OPERATIONS
    int choice;
    int loc,elem;
    L.append(100);
    cout<<"THE FOLLOWING OPERATIONS CAN BE PERFORMED ON THE LINKED LIST:"<<endl;
    cout<<"1.Insert before another element"<<endl;
    cout<<"2.Insert after another element"<<endl;
    cout<<"3.Delete an element"<<endl;
    cout<<"4.Traverse the list"<<endl;
    cout<<"5.Reverse the list"<<endl;
    cout<<"6.Sort the list"<<endl;
    cout<<"7.Delete alternate elements"<<endl;
    cout<<"8.Insert in an order"<<endl;
    cout<<"9.Exit"<<endl;
    while(true){
        cout<<">";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the element to insert before:";
                cin>>loc;
                cout<<"Enter the element to insert:";
                cin>>elem;
                L.insert_before(elem, loc);
                break;
            case 2:
                cout<<"Enter the element to insert after:";
                cin>>loc;
                cout<<"Enter the element to insert:";
                cin>>elem;
                L.insert_after(elem, loc);
                break;
            case 3:
                cout<<"Enter the element to delete:";
                cin>>elem;
                L.remove(elem);
                break;
            case 4:
                L.traverse();
                break;
            case 5:
                L.reverse();
                break;
            case 6:
                cout<<"0 for Ascending\n1 for Descending";
                cin>>elem;
                L.sort(elem);
                break;
            case 7:
                L.delete_alternate();
                break;
            case 8:
                cout<<"Enter the element to insert:";
                cin>>elem;
                L.insert_sort(elem);
                break;
            case 9:
                return 0;
            default:
                cout<<"Invalid Choice!"<<endl;
        }
    }
}