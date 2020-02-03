// Program to perform traversals(BFS and DFS) using 1-indexing
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
        adj = new int*[n+1];
        for(int i=0;i<n+1; ++i)
            adj[i] = new int[n+1];
        for(int i=0;i<n+1;++i){
            for(int j=0;j<n+1;j++)
                adj[i][j] = 0;
        }
    }
    void addVertex(int src, int dest){
        adj[src][dest]=1;
        adj[dest][src]=1;
    }
    void DFS(int source){
        bool visited[n+1] = {false};
        stack <int> s;
        s.push(source);
        visited[source] = true;
        while(!s.empty()){
            int curr = s.top();
            s.pop();
            for(int i=1;i<n+1;i++){
                if(adj[curr][i]==1 && !visited[i]){
                    visited[i]=true;
                    s.push(i);
                }
            }
            cout<<curr<<" ";
        }
        cout<<endl;
    }

    void BFS(int source){
        bool visited[n+1]={false};
        queue <int> s;
        s.push(source);
        visited[source]=true;
        while(!s.empty()){
            int c=s.front();
            s.pop();
            for(int i=1;i<n+1;i++){
                if(adj[c][i]==1 && !visited[i]){
                    visited[i]=true;
                    s.push(i);
                }
            }
            cout<<c<<" ";
        }
        cout<<endl;
    }
};

int main(){
    UGraph G(6);
    G.addVertex(6,4);
    G.addVertex(4,3);
    G.addVertex(3,2);
    G.addVertex(2,5);
    G.addVertex(2,1);
    G.addVertex(1,5);
    G.addVertex(4,5);
    cout<<"BFS: ";
    G.BFS(1);
    cout<<"DFS: ";
    G.DFS(1);
}
