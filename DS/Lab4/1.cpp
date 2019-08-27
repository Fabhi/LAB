#include <iostream>
using namespace std;
const int SIZE=10;

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
        if (front==-1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if ((front==0 && rear==SIZE-1)||(front==rear+1)){
            return true;
        }
        return false;
    }

    int enq(int elem){
        if(isFull())
            cout<<"Queue Full"<<endl;
        else{
            if(front==-1)
                front=0;
            rear=(rear+1)%SIZE;
            arr[rear]=elem;
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
    }

    void display(){
        for (int i=front;i!=rear;i=(i+1)%SIZE){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        for(int i=0;i<SIZE;i++){
            cout<<arr[i]<<' ';
        }
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
    C.enq(4);
    C.enq(5);
    C.enq(6);
    C.enq(7);
    C.enq(8);
    C.enq(9);
    C.enq(10);
    C.display();
    C.deq();
    C.deq();
    C.enq(11);
    C.enq(12);
    C.display();
}