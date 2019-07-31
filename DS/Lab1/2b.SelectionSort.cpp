#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter the element at position "<<i<<":";
        cin>>a[i];
    }
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
    for(int i=0;i<n;i++){
        cout<<"\n"<<a[i]<<endl;
    }
}