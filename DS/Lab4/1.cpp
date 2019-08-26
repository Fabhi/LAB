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

    
};