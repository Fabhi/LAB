#include <iostream>
using namespace std;

int LinearSearch(int a[], int n, int elem){
    int f=0;
    for(int i=0;i<n;i++){
        if(elem==a[i]){
            cout<<"Element found at "<<i;
            f=1;
            return 0;
            }
        }

    if (f == 0){
        cout<<"\nElement not found\n";
    }
    return 0;
}


int BinarySearch(int a[],int n, int elem){
    int low=0, mid, high=n-1;
    while(low<high){
        mid=(low+high)/2;
        if(elem<a[mid]){
            high=mid-1;}
        else if(elem>a[mid]){
            low=mid+1;
        }
        else{
            cout<<"Element found at "<<mid;
            return 0;
        }
    cout<<"Element not found";
    return -1;
    }
}

int main(){
    cout<<"Number of elements:";
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter elm";
    int elem;
    cin>>elem;
    int lLoc=LinearSearch(a,n,elem);
    int bLoc=BinarySearch(a,n,elem);
    cout<<"Element found at location using Linear search:"<<lLoc;
    cout<<"Element found at location using Binary search:"<<bLoc;
}