//Program to implement singly linked list
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct node{
    int data;
    node* next; //Pointer to type node
};

class list{
    private:
    node *head, *tail; // Every linked list has a head and a tail
    public:
    static int counter;
    list(){
        head=NULL;
        tail=NULL;
    }
    void insertbeg(int elem);
    void insert(int elem, int loc);
    void insertend(int elem);
    void display();
    void removebeg();
    void remove(int loc);
    void removeend();
    void sort();
    void reverse();
    void search(int elem);
    void sortinsert(int elem);
};

int list::counter=0;

void list::insertbeg(int elem){
        node *temp=new node;
        temp->data=elem;
        temp->next=head;
        head=temp;
        counter++; 
}

void list::insert(int elem, int loc=0){
    if(loc==0){
        insertbeg(elem);   
    }
    else if(loc<counter && loc>0){
        node *temp= new node;
        node *pre= new node;
        node *cur= new node;
        cur=head;
        for(int i=0;i<loc;i++){
            pre=cur;
            cur=cur->next;
        }
        temp->data=elem;
        pre->next=temp;
        temp->next=cur;
        counter++;}
    else if(loc==counter){
        insertend(elem);
    }
    else{
        cout<<"Index out of bound"<<endl;
    }
}

void list::insertend(int elem){
    node *temp=new node;
    temp->data=elem;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        tail=temp;
        temp=NULL;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
    counter++;
}

void list::display(){
    node *temp=new node;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void list::search(int elem){
    
}

int main(){
    list l;
    l.append(10);
    l.append(100);
    l.display();
    l.insertbeg(10);
    l.insert(132,3);
    l.display();
}