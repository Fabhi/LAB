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
        if (front==-1&& rear==-1){
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
        if(isEmpty())
            cout<<"Empty queue"<<endl;
        else{
            int elem=arr[front];
            if (front==rear)
                front=rear=-1;
            else
                front=(front+1)%SIZE;
            return elem;
        }
        return -1;
    }

    void display(){
        int i;
        for (i=front;i!=rear;i=(i+1)%SIZE){
            cout<<arr[i]<<' ';
        }
        cout<<arr[i]<<' ';
        cout<<endl;
    }
};

int main(){
    CQueue C;
    C.deq();
    C.enq(0);
    C.enq(1);
    C.enq(2);
    C.enq(3);
    C.display();
    C.deq();
    C.deq();
    C.enq(11);
    C.enq(12);
    C.display();
}