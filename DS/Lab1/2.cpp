#include <iostream>
using namespace std;

void bubbleSort(int a[], int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j]>a[j+1]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}

void selectionSort(int a[], int n){
    int temp;
    int min;
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

void insertionSort(int array[], int size){
  for(int step=1; step<size; step++){
    int key = array[step];
    int j=step-1;
    while(key<array[j] && j>=0){
        array[j+1] = array[j];
        --j;
    }
    array[j+1]=key;
  }
}



int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter the element at position "<<i<<":\n";
        cin>>a[i];
    }
    bubbleSort(a,n);
    cout<<endl<<"Bubble Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    selectionSort(a,n);
    cout<<endl<<"Selection Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    insertionSort(a,n);
    cout<<endl<<"Insertion Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}