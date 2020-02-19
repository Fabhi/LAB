// Program to find minimum cost spanning tree using prim's alogrithm
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int inf=9999;
class UGraph{
    private:
    int** adj;
    int n;
    public:
    UGraph(int numb){
        n = numb+1;
        adj = new int*[n];
        for(int i=0;i<n; ++i)
            adj[i] = new int[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;j++)
                adj[i][j] = inf;
            adj[i][i]=0;
        }
    }
    void addVertex(int src, int dest, int cost){
        adj[src][dest]=cost;
        adj[dest][src]=cost;
    }
    int min(int arr[]){
        int min=arr[1];
        for(int i=2;i<n;i++){
            if(arr[i]<min)
                min=arr[i];
        }
    }

    int leastCostEdge(int u, int min){
        for(int i=1;i<n;i++){
            if(adj[u][i]<min){
                return i;
            }
        }
    }
    void KruskalMST(){
        int min= leastCostEdge();
    }

    void print(){
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    // int n;
    // cout<<"Enter size:";
    // cin>>n;
    // UGraph G(n);
    // cout<<"Enter edges and cost:"<<endl;
    // int a, b, cost;
    // while(true){
    //     cin>>a>>b>>cost;
    //     if(a!=-1 && b!=-1)
    //         G.addVertex(a,b,cost);
    //     else
    //         break;
    // }
    UGraph G(6);
    G.addVertex(1,2,28);
    G.addVertex(1,5,10);
    G.addVertex(3,2,16);
    G.addVertex(6,2,11);
    G.addVertex(3,4,12);
    G.addVertex(4,6,18);
    G.addVertex(4,5,25);
    G.addVertex(5,6,19);
    G.print();

}