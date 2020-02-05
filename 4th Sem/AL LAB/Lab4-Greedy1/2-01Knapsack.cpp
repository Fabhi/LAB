#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool* load_container(int max, int* weights, int n){
    sort(weights, weights+n);
    int temp=max;
    bool* taken=new bool[n];
    int i=0;
    while(true){
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
    cout>>"Enter weight value pairs:
    int weights[n], values[n];
    for(int i=0;i<n;i++)
        cin>>weights[i]>>values[i];
    
    bool *taken = load_knapsack(max, arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"-> "<<taken[i]<<endl;
