// Program to perform traversals(BFS and DFS)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class UGraph{
    int** adj;
    int n;
    UGraph(int numb){
        n = numb;
        // Dynamically initializing a 2D adjay
        adj = new int*[n];
        for(int i=0;i<n; ++i)
            adj[i] = new int[n];
        // Initialize as 0
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
        bool visited[n]= {false};
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
                }
            }
            cout<<curr<<" ";
            for(int i=0;i<n;i++){
                cout<<visited[i]<<" ";
            }
            cout<<endl; 
        }
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
                }
            }
            cout<<c<<" ";
            for(int i=0;i<n;i++){
                cout<<visited[i]<<" ";
            }
            cout<<endl;
        }
    }
};
