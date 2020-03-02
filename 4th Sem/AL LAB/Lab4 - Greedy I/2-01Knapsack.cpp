// 0-1 Knapsack
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class item{
    public:
    int weight;
    int value;
};

bool sort_weight(item i1, item i2){
    return i1.weight<i2.weight;
}

bool sort_value(item i1, item i2){
    return i1.value>i2.value;
}

bool sort_density(item i1, item i2){
    return i1.value/(float)i1.weight >i2.value/(float)i2.weight;
    
}

int sort_helper(item items[],int n,string s){
    if(s=="weight")
        sort(items,items+n,sort_weight);
    else if(s=="profit")
        sort(items,items+n,sort_value);
    else if(s=="density")
        sort(items,items+n,sort_density);
    else{
        cout<<"Invalid Parameter";
        return 0;
    }
    return 1;
}

void load_knapsack(int max, item items[], int n, string s){
    if (!sort_helper(items,n,s)) return;
    bool* taken = new bool[n];
    for(int i=0;i<n;i++) 
        taken[i]=false;
    int used = max;
    int profit=0;
    int i=0;
    while(i<n){
        if((max-items[i].weight)>=0){
            max-=items[i].weight;
            profit+=items[i].value;
            taken[i]=true;
        }
        else
            break;
        i++;
    }
    cout<<"Weight used: "<< used-max<<endl;
    cout<<"Profit obtained: "<<profit<<endl;
    for(int i=0;i<n;i++)
        cout<<"( "<<items[i].weight<<", "<<items[i].value<<" )-> "<<taken[i]<<endl; 
}

int main(){
    int max;
    cout<<"Enter max weight:";
    cin>>max;
    int n;
    cout<<"Enter number of objects:";
    cin>>n;
    cout<<"Enter weight value pairs: \n";
    item items[n];
    for(int i=0;i<n;i++)
        cin>>items[i].weight>>items[i].value;
    
    cout<<"\n\nGreedy by Weight\n";
    cout<<"=============================\n";
    load_knapsack(max, items, n, "weight");
    cout<<"\n\nGreedy by Profit\n";
    cout<<"=============================\n";
    load_knapsack(max, items, n, "profit");
    cout<<"\n\nGreedy by Density\n";
    cout<<"=============================\n";
    load_knapsack(max, items, n, "density");
}

// 15
// 7
// 1 5
// 3 10
// 5 15
// 4 7
// 1 8
// 3 9
// 2 4