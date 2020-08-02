#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class item{
    public:
    int weight;
    int value;
};

int** Lookup;
int n;
int c;
item *items;


int f(int x, int y){
    if(x<0)
        return 0;
    if(Lookup[x][y]!=-1)
        return Lookup[x][y];
    if(x==n-1){
        if (items[x].weight%2 == 0 && y>=items[x].weight)
            Lookup[x][y] = items[x].value;
        else
            Lookup[x][y] = 0;
        return Lookup[x][y];
    }
    if(y<items[x].weight || items[x].weight%2!=0)
        Lookup[x][y] = f(x+1,y);
    else
        Lookup[x][y]= max( f(x+1,y), f(x+1,y-items[x].weight)+ items[x].value);
    return Lookup[x][y];
}

void load_knapsack(){
    Lookup = new int*[n];
    for(int i = 0; i < n; ++i)
        Lookup[i] = new int[c+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<c+1;j++)
            Lookup[i][j]=-1;
    }
    cout<<f(n-1,c)<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<c+1;j++){
            cout<<Lookup[i][j]<<" ";
        }
        cout<<"\n";
    }
    

}
int main(){
    cout<<"Enter max weight:";
    cin>>c;
    cout<<"Enter number of objects:";
    cin>>n;
    cout<<"Enter weight value pairs: \n";
    items = new item[n];
    for(int i=0;i<n;i++)
        cin>>items[i].weight>>items[i].value;
    load_knapsack();
}