// Program to merge two single linked list

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createList(){
    Node *temp= new Node;
    cout<<">";
    int elem;
    cin>>elem;
    if(elem==-1)
        return NULL;
    else{
        temp->data=elem;
        temp->next=createList();
        return temp;
    }
}

void traverse(Node *temp){
    cout<<temp->data<<" ";
    if(temp->next)
        traverse(temp->next);
    return;
}

void merge(Node* head3, Node *head, Node *head2){
    if(!head){
        head3=head2;
        return;
    }
    else if(!head2){
        head3=head;
        return;
    }
    else{
        if(head->data<head2->data){
            head3=head;
            merge(head3->next, head->next,head2);
        }
        else{
            head3=head2;
            merge(head3->next, head,head2->next);
        }
    }
}

int main(){
    Node *head = createList();
    Node *head2 = createList();
    Node *head3=new Node;
    merge(head3, head, head2);
    traverse(head);
    traverse(head2);
    traverse(head3);
}