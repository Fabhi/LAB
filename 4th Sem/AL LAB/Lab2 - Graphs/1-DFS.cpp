// Program to perform DFS using 1-indexing
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
    }
};

int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    UGraph G(n);
    cout<<"Enter edges:"<<endl;
    int a, b;
    while(true){
        cin>>a>>b;
        if(a!=-1 && b!=-1)
            G.addVertex(a,b);
        else
            break;
    }
    cout<<"Enter starting edge:";
    cin>>n;
    cout<<"DFS: ";
    G.DFS(n);
}
