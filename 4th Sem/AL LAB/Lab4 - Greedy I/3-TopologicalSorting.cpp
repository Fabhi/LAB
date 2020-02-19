// Topological sorting
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int arr[],int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

class Graph{
    private:
    int** adj;
    int n;
    public:
    Graph(int numb){
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
    }
    void TopologicalSort(){
        int indegree[n+1] = {0};       //1.To store the indegree of each vertex
        bool visited[n+1] = {false};  // 2.To mark each vertex as visited or not vistited
        int T[n+1];                  //  3.Contains the final answer to the topological sort
        queue <int> s;
        for(int i=1;i<=n;i++){     //    4.Develop indegree array
          for(int j=1;j<=n;j++){
                if(adj[j][i])
                    indegree[i]++;
            }
        }
        print(indegree,n);
        for(int i=1;i<=n;i++){   //      5.If indegree is 0, then push to queue and mark as visited
            if(!indegree[i]){
                s.push(i);
                visited[i] = true;
            }
        }
        int j=1;
        while(!s.empty()){
            int a = s.front();
            s.pop();
            T[j++] = a;           //       6. Push to the solution array every pop from the queue.
            for(int i=1; i<=n;i++){
                if(adj[a][i] && !visited[i]){
                    indegree[i]--;
                    if(!indegree[i]){
                        s.push(i);
                        visited[i]=true;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
            cout<<T[i]<<" ";
        cout<<endl;
    }
};

int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    Graph G(n);
    cout<<"Enter edges:"<<endl;
    int a, b;
    while(true){
        cin>>a>>b;
        if(a!=-1 && b!=-1)
            G.addVertex(a,b);
        else
            break;
    }
    G.TopologicalSort();
}
// 7
// 1 2 
// 1 3 
// 1 4
// 2 4
// 2 5
// 3 4
// 3 6
// 4 6
// 4 7
// 5 4
// 5 7
// 7 6
// -1 -1

// Answer = 1 2 3 4 5 7 6