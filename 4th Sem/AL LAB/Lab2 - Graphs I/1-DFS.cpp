// Program to perform DFS using 1-indexing
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void showstack(stack <int> s) {
    // Function to display contents of a stack (Debugging function) 
    stack <int> q;
    while (!s.empty()){ 
        cout << s.top()<<' '; 
        q.push(s.top()); 
        s.pop();
    } 
    cout << '\n';
    while (!q.empty()){  
        s.push(q.top()); 
        q.pop();
    }
}

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
        int curr=source;
        cout<<curr<<" ";
        while(!s.empty()){
            bool explored=true;
            for(int i=1;i<n+1;i++){
                if(adj[curr][i]==1 && !visited[i]){
                    visited[i]=true;
                    explored=false;
                    curr=i;
                    cout<<curr<<" ";
                    s.push(i);
                    break;
                }
            }
            if(explored){
                curr=s.top();
                s.pop();
            }
        }
    }
};

int main(){
    // Menu Driven Data
    // int n;
    // cout<<"Enter size:";
    // cin>>n;
    // UGraph G(n);
    // cout<<"Enter edges:"<<endl;
    // int a, b;
    // while(true){
    //     cin>>a>>b;
    //     if(a!=-1 && b!=-1)
    //         G.addVertex(a,b);
    //     else
    //         break;
    // }
    // cout<<"Enter starting edge:";
    // cin>>n;
    // cout<<"DFS: ";
    // G.DFS(n);
    
    
    // Hard coded data
    UGraph G(6);
    G.addVertex(1,2);
    G.addVertex(1,5);
    G.addVertex(3,2);
    G.addVertex(6,2);
    G.addVertex(3,4);
    G.addVertex(4,6);
    G.addVertex(4,5);
    G.addVertex(5,6);
    cout<<"Enter starting edge:";
    int n;
    cin>>n;
    cout<<"DFS: ";
    G.DFS(n);
}
