#include<iostream>
#include<queue>

using namespace std;

class Node{
	public:
	int val;
	Node* next = NULL;
};

void add(Node*& head, int val){
	if(!head){
		head = new Node;
		head->val = val;
		return;
	}
	Node* temp = head;
	while(temp->next != NULL)
		temp = temp->next;
		
	Node* newn = new Node;
	newn->val = val;
	temp->next = newn;
}

bool motherVertexHelper(Node* graph[], int n, int src){
	queue<int> q;
	int visited[n];
	for(int i=0;i<n;i++){
		visited[i] = 0;
	}
	visited[src] = 1;
	int numvis = 1;
	q.push(src);
	
	while(!q.empty()){
		Node* temp = graph[q.front()];
		numvis++;
		q.pop();
		
		while(temp != NULL){
			if(visited[temp->val] == 0){
				visited[temp->val] = 1;
				q.push(temp->val);
			}
			temp = temp->next;
		}
	}
	return (numvis == n);
}

void motherVertex(Node* graph[], int n){
	cout << "Mother Vertex are:";
	for(int i=1;i<n;i++){
		if(motherVertexHelper(graph, n, i)) cout << i << " ";
	}
}
int main(){
	Node* graph[6];
	for(int i=0;i<6;i++){
		graph[i] = NULL;
	}
	add(graph[1], 3);
	add(graph[1], 4);
	add(graph[2], 1);
	add(graph[3], 2);
	add(graph[4], 5);
	
	int visited[6] = {0};
	motherVertex(graph, 6);
}