// Greedy on Weight
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sortpair(int* key_array, int* sec_array, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(key_array[j]>key_array[j+1]){
                swap(key_array[j],key_array[j+1]);
                swap(sec_array[j],sec_array[j+1]);
            }
        }
    }
}

bool* load_knapsack(int max, int* weights, int* values, int n){
    sortpair(weights, values, n);
    int temp = max;
    bool* taken = new bool[n];
    int i=0;
    int profit=0;
    while(i<n){
        if((max-weights[i])>=0){
            max-=weights[i];
            profit+=values[i];
            taken[i]=true;
        }
        else
            break;
        i++;
    }
    cout<<"Weight used:"<< temp-max<<endl;
    cout<<"Profit obtained:"<<profit<<endl;
    return taken;    
}

int main(){
    int max;
    cout<<"Enter max weight:";
    cin>>max;
    int n;
    cout<<"Enter number of objects:";
    cin>>n;
    cout<<"Enter weight value pairs: ";
    int weights[n], values[n];
    for(int i=0;i<n;i++)
        cin>>weights[i]>>values[i];
    
    bool *taken = load_knapsack(max, weights, values, n);
    for(int i=0;i<n;i++)
        cout<<"( "<<weights[i]<<", "<<values[i]<<" )-> "<<taken[i]<<endl;
}