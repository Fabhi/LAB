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

bool path(Node* graph[], int visited[], int src, int dest){
	Node* temp = graph[src];
	while(temp != NULL){
		if(visited[temp->val] == 0){
			if (temp->val == dest || path(graph, visited, temp->val, dest)){
				visited[temp->val] = 1;
				return true;
			}
		}
		temp = temp->next;
	}
	return false;
}


bool cycles(Node* graph[], int n){
	bool found = false;
	for(int i=1;i<n;i++){
		int visited[n]={0};
		if(path(graph, visited, i, i)) 
			found = true;
	}
	return found;
}

int main(){
	int n;
    cout<<"Enter size:";
    cin>>n;
	Node* graph[n]= {NULL};
    cout<<"Enter edges:"<<endl;
    int a=0,b=0;
    while(true){
        cin>>a>>b;
        if(a!=-1 && b!=-1)
            add(graph[a], b);
        else
            break;
    }
    cycles(graph,n)?cout<<"Cycle exists":cout<<"Cycle absent";
}