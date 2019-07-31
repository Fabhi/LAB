#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter the element at position "<<i<<":\n";
        cin>>a[i];
    }
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
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}