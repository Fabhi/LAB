#include <iostream>
using namespace std;

void bubbleSort(int a[], int n){
    int temp;
    int count=0;
    for(int i=0;i<n;i++){
        count++;
        for(int j=0;j<n;j++){
            if(a[j]>a[j+1]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<endl<<count<<endl;
}

void selectionSort(int a[], int n){
    int temp;
    int count=0;
    int min;
    for(int i=0;i<n;i++){
        count++;
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
    cout<<endl<<count<<endl;
}

void insertionSort(int array[], int size){
    int count=0;
    for(int step=1; step<size; step++){
        count++;
        int key = array[step];
        int j=step-1;
        while(key<array[j] && j>=0){
            array[j+1] = array[j];
            --j;
        }
        array[j+1]=key;
    }
    cout<<endl<<count<<endl;
}



int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter the element at position "<<i<<":\n";
        cin>>a[i];
        b[i]=a[i];
        c[i]=a[i];
    }
    
    bubbleSort(a,n);
    cout<<endl<<"Bubble Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    selectionSort(b,n);
    cout<<endl<<"Selection Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    insertionSort(c,n);
    cout<<endl<<"Insertion Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
    }
}