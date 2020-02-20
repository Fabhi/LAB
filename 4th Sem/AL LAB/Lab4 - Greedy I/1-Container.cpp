#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool* load_container(int max, int* weights, int n){
    sort(weights, weights+n);
    int temp=max;
    bool* taken=new bool[n];
    int i=0;
    while(i<n){
        if((max-weights[i])>=0){
            max-=weights[i];
            taken[i]=true;
        }
        else
            break;
        i++;
    }
    cout<<"Weight used:"<< temp-max<<endl;
    return taken;    
}

int main(){
    int max;
    cout<<"Enter max weight:";
    cin>>max;
    int n;
    cout<<"Enter number of objects:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    bool *taken = load_container(max, arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"-> "<<taken[i]<<endl;
}
