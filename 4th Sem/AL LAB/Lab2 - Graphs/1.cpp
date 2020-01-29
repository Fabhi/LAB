// Program to perform traversals(BFS and DFS)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class UGraph{
    private:
    int** adj;
    int n;
    public:
    UGraph(int numb){
        n = numb;
        adj = new int*[n];
        for(int i=0;i<n; ++i)
            adj[i] = new int[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;j++)
                adj[i][j] = 0;
        }
    }
    void addVertex(int src, int dest){
        adj[src][dest]=1;
        adj[dest][src]=1;
    }
    void DFS(int source){
        bool visited[n] = {false};
        stack <int> s;
        s.push(source);
        visited[source] = true;
        while(!s.empty()){
            int curr = s.top();
            s.pop();
            for(int i=0;i<n;i++){
                if(adj[curr][i]==1 && !visited[i]){
                    visited[i]=true;
                    s.push(i);
                    cout<<i<<" ";
                }
            }
        }
        cout<<endl;
    }

    void BFS(int source){
        bool visited[n]={false};
        queue <int> s;
        s.push(source);
        visited[source]=true;
        while(!s.empty()){
            int c=s.front();
            s.pop();
            for(int i=0;i<n;i++){
                if(adj[c][i]==1 && !visited[i]){
                    visited[i]=true;
                    s.push(i);
                    cout<<i<<" ";
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    UGraph G(6);
    G.addVertex(1,0);
    G.addVertex(1,2);
    G.addVertex(0,3);
    G.addVertex(3,4);
    G.addVertex(2,0);
    G.addVertex(1,5);
    cout<<"BFS: ";
    G.BFS(2);
    cout<<"DFS: ";
    G.DFS(2);
}
