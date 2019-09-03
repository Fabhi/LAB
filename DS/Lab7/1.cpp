//Program to implement singly linked list
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct node{
    int elem;
    node* next; //Pointer to type node
    }

class list{
    private:
    node *head, *tail; // Every linked list has a head and a tail
    list(){
        head=tail=NULL;
    }

    int append(int elem){
        node* temp=new node;
        temp->data=elem;
        temp->next=NULL;
        if(head == NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=tail->next;
        }
    }    
};