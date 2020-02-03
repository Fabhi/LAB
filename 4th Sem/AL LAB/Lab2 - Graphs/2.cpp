//Program to find the mother vertex for a directed Connected Graph

// 1.Perform DFS on given graph, while keeping track of last visited vertex
// 2.Check is one of the vertex is a mother vertex by perfroming DFS from that vertex


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d){
       data=d;
       next=NULL;
    }
};

class Graph{
    int n;
    Node* arr[];
    
    public:
    Graph(int num){
        n=num;
        arr = new Node*[n+1];
        for(int i=1;i<n+1;i++)
            arr[i]=NULL;
    }
    
    void addVertex(int src, int dest){
        Node* curr=arr[src];
        while(curr)
            curr=curr->next;
        curr->next=new Node(dest);
    }
    
    int DeepestVertex(int src){
        bool visited[n+1] = {false};
        stack <int> s;
        s.push(src);
        int dV = 0;
        visited[src]=true;
        while(!s.empty()){
            int curr=s.top();
            s.pop();
            bool finalVertex=true;
            for(int i=1; i<n+1; i++){
                if(!visited[i]){
                    finalVertex=false;
                    Node* trav = arr[i];
                    while(trav){
                        if(trav->data==curr){
                            visited[i]=true;
                            s.push(i);
                            break;
                        }
                        trav=trav->next;
                    }
                }
            }
            if(finalVertex)
                return curr;
        }
    }
};

int main(){
    Graph G(6);
    G.addVertex(6,4);
    G.addVertex(4,3);
    G.addVertex(3,2);
    G.addVertex(2,5);
    G.addVertex(2,1);
    G.addVertex(1,5);
    G.addVertex(4,5);
    cout<<G.DeepestVertex(1);
}

