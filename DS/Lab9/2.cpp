//Program to represemt a polynomial using Circular Doubly Linked List
#include <iostream>
using namespace std;
struct node{
    int coff;
    int exp;
    node *prev;
    node *next;
};

class Poly{
    private:
    node *head;
    public:
    Poly(){
        head=NULL;
    }

    void append(int c, int e){
        node *temp= new node;
        node *trav= new node;
        temp->coff=c;
        temp->exp=e;
        trav=head;
        if(trav==NULL){
            head=temp;
            temp->next=head;
            temp->prev=head;
            return;
        }
        trav->prev->next=temp;
        trav->prev=temp;
        temp->next=trav;
        temp->prev=trav->prev;
    }

    void input(){
        int c,e;
        cout<<"Enter the polynomial."<<endl;
        while(true){
            cout<<"Enter the coff:";
            cin>>c;
            cout<<"Enter the exp:";
            cin>>e;
            append(c,e);
            if(e==0)
                break;
        }
    }

    void add(Poly p1, Poly p2){
        // Copy one polynomial
        node *trav= new node;
        trav=p1.head;
        do{
            append(trav->coff,trav->exp);
            trav=trav->next;
        }while(trav!=p1.head);
        // Add second polynomial
        trav=p2.head;
        bool found;
        do{
            found=false;
            node *temp= head;
            do{
                if(trav->exp==temp->exp){
                    found=true;
                    temp->coff=temp->coff+trav->coff;
                    break;
                }
                temp=temp->next;
            }while(temp!=head);
            if(!found){
                node *value= new node;
                value->exp=trav->exp;
                value->coff=trav->coff;
                node *ex=head;
                do{
                    if(ex->exp>trav->exp){
                        value->next=ex->next;
                        value->prev=ex;
                        ex->next->prev=value;
                        ex->next=value;
                    } 
                }while(ex!=head);
            }
            trav=trav->next;
        }while(trav!=p2.head);
    }

    void display(){
        node *trav= new node;
        trav=head;
        do{
            cout<<trav->coff<<"x^"<<trav->exp<<" + ";
            trav=trav->next;
        }while(trav->next!=head);
        cout<<trav->coff;
        cout<<endl;
    }
};

int main(){
    Poly P1,P2,P3;
    P1.input();
    P2.input();
    P3.add(P1, P2);
    cout<<"Polynomial 1:";
    P1.display();
    cout<<"Polynomial 2:";
    P2.display();
    cout<<"Polynomial 3:";
    P3.display();
}