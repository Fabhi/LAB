#include <iostream>
using namespace std;
const int SIZE=100;
class Queue{
    private:
    int front;
    int rear;
    int arr[SIZE];
    public:
    Queue(){
        rear=front=-1;
    }

    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        return false;
    }
    
    bool isFull(){
        if(rear==SIZE-1){
            return true;
        }
        return false;
    }
    
    int enq(int elem){
        if(isEmpty()){
            arr[rear++]=elem;
            front++;
            return 0;
        }
        else if(isFull()){
            return -1;
        }
        arr[rear++]=elem;

    }
    int deq(){
        if(isEmpty()){
            cout<<"Empty Queue";    
        }
        else if(front==rear){
            int temp=arr[rear];
            front=rear=-1;
            return temp;
        }
        else{
            return arr[front++];
        }
    }
    
    void display(){
        for(int i=front;i<rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue Q;
        Q.enq(1);
        Q.deq();
        Q.enq(2);
        Q.enq(3);
        Q.enq(4);
        Q.deq();
        Q.deq();
        Q.enq(5);
        Q.display();

}