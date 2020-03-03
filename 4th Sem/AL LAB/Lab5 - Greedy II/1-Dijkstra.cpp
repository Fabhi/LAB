//Program to implement Dijkstra Algorithm
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;
const int inf=9999;

class Graph{
    private:
    int** adj;
    int n;
    public:
    Graph(int numb){
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
    }

    void dijkstra(int src){
        int cost[n];
        int pre[n] = {0};
        bool visited[n] = {false};

        // Intializing priority queue using lambda function
        auto compare = 
        [=](int lhs, int rhs){
             return adj[src][lhs] > adj[src][rhs];
             };
        priority_queue <int, vector<int>, decltype(compare) > list(compare);
        
        
        for(int i=1;i<n;i++){
            cost[i] = adj[src][i]; //Intialize Predecessor and Cost array
            if(cost[i]!=inf&& cost[i]!=0){
                pre[i]=src;
                list.push(i);
                visited[i] = true;
            }
        }

        while(!list.empty()){
            int i = list.top();
            list.pop();
            for(int j=1;j<n;j++){
                int temp = min(cost[j], cost[i]+adj[i][j]);
                if(temp != cost[j]){
                    cost[j] = temp;
                    pre[j] = i;
                    if(!visited[j]){
                        list.push(j);
                        visited[j]=true;
                    }
                }
            }
        }

        cout<<"             ";
        for(int i=1;i<n;i++)
            cout<<i<<" ";
        cout<<endl<<"Cost:        ";
        for(int i=1;i<n;i++)
            cout<<cost[i]<<" ";
        cout<<endl<<"Predecessor: ";
        for(int i=1;i<n;i++)
            cout<<pre[i]<<" ";                
    }
};

int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    Graph G(n);
    cout<<"Enter edges and cost: (<-1, -1> to stop)"<<endl;
    int a, b, cost;
    while(true){
        cin>>a>>b>>cost;
        if(a!=-1 && b!=-1)
            G.addVertex(a,b,cost);
        else
            break;
    }
}
    // Graph G(5);
    // G.addVertex(1,2,6);
    // G.addVertex(1,4,1);
    // G.addVertex(2,5,2);
    // G.addVertex(2,3,5);
    // G.addVertex(4,2,2);
    // G.addVertex(4,5,1);
    // G.addVertex(5,3,5);
    // G.dijkstra(1);