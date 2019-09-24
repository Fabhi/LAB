// Program to implement doubly linked list
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next, *prev;
};

class DoublyCircular{
    private:
    Node *head;
    public:
    DoublyCircular(){
        head=NULL;
    }

    void insert(int elem, int loc){
        Node *temp= new Node;
        Node *trav= new Node;
        temp->data=elem;
        if(head==NULL){
            head=temp;
            temp->next=head;
            temp->prev=head;
            return;
        }
        bool found=false;
        trav=head;
        int count=0;
        do{
            if(count==loc){
                break;
                found=true;
            }
            count++;
            trav=trav->next;            
        }while(trav!=head);

        if(count<loc){
            cout<<"Index out of bound"<<endl;
            return;
        }

        trav->prev->next=temp;
        temp->prev=trav->prev;
        temp->next=trav;
        trav->prev=temp;
    }

    // TODO: Delete an element from an doubly linked circular list

    void display(){
        Node *trav= new Node;
        trav=head;
        do{
            cout<<trav->data<<' ';
            trav=trav->next;
        }while(trav!=head);
        cout<<endl;
    }
};

int main(){
    DoublyCircular c;
    c.insert(10,0);
    c.display();
    c.insert(11,1);
    c.insert(12,1);
    c.insert(13,4);
    c.display();

}