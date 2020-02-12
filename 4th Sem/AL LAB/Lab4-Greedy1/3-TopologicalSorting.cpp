// Topological sorting
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
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

    bool checkCycle(){
        for (int i=0;i<n;i++){

        }
    }
    void TopologicalSort(){
        // checkCycle()?cout<<"Graph contains cycle":cout<<"No cycles detected";
        int indegree[n+1] = {0};
        bool visited[n+1] = {false};
        queue <int> s;
        int T[n+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(adj[j][i])
                    indegree[i]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(!indegree[i]){
                s.push(i);
                visited[i] = true;
            }
        }
        int j=1;
        while(!s.empty()){
            int a = s.front();
            T[j++] = a;
            cout<<a<<" ";
            for(int i=1; i<=n;i++){
                if(adj[a][i] && !visited[i]){
                    indegree[i]--;
                    if(!indegree[i])
                        s.push(i);
                        visited[i]=true;
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