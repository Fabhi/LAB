//Program to implement Circular Queues using Arrays
#include <iostream>
using namespace std;
const int SIZE=5;

class CQueue{
    private:
    int front;
    int rear;
    int arr[SIZE];
    public:
    CQueue(){
        front=-1;
        rear=-1;
    }

    bool isEmpty(){
        if (front==-1 && rear==-1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if ((front==0 && rear==SIZE-1)||(front==(rear+1))){
            return true;
        }
        return false;
    }

    int enq(int elem){
        if(isFull()){
            cout<<"Queue Full"<<endl;
            return -1;}  
        else{
            if(isEmpty())
                front=0;
            rear=(rear+1)%SIZE;
            arr[rear]=elem;
            return 1;
        }
    }

    int deq(){
        if(isEmpty()){
            cout<<"Empty queue"<<endl;
            return -1;}
        else{
            int elem=arr[front];
            if (front==rear)
                front=rear=-1;
            else
                front=(front+1)%SIZE;
            return elem;
        }
    }

    void display(){
        int i;
        for (i=front;i!=rear;i=(i+1)%SIZE){
            cout<<arr[i]<<' ';
        }
        cout<<arr[i]<<endl;
    }
};

int main(){
    CQueue cq;
    int choice, item;
    do
    {
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Input the element for insertion in queue : ";
            cin>>item;	
            cq.enq(item);
	        break;
	    case 2:
            cq.deq();
	        break;
        case 3:
            cq.display();
	        break;
	    case 4:
	        break;
	    default:
	        cout<<"Wrong choice"<<endl;
	    }
    } while(choice != 4);
    return 0;

}
