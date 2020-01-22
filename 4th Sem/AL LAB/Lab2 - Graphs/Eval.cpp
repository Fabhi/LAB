// For a given input string create a linked list and display the positions of all occurences of two consecutive vowels
#include <iostream>
using namespace std;


struct node{
    char data;
    node *next;
};

class LinkedList{
    private:
    node *head;
    int count;
    public:

    LinkedList(){
        head=NULL;
        count=0;
    }

    void append(char elem){
        node *temp= new node;
        temp->data=elem;
        temp->next=head;
        head=temp;
        count++;
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

    bool vowel(char a){
        switch(a){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
                break;
            default:
                return false;
        }
    }

    void find(){
        const int vowels[] = {'a','b','c','d','e'};
        node *trav = head;
        node *trav2 = head->next;
        bool found[count]= {false};
        int loc=0;
        while(trav2){
            loc++;
            if(vowel(trav->data) && vowel(trav2->data))
                cout<<loc<<" "<<loc+1<<endl;
            trav=trav->next;
            trav2=trav2->next;
        }
    }
};

int main(){
    string s;
    cout<<"Enter string:";
    cin>>s;
    LinkedList L;
    int len = s.length();
    for(int i=len-1;i>=0;i--)
        L.append(s[i]);
    L.traverse();
    L.find();
}