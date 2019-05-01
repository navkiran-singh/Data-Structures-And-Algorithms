#include<iostream>
#include<queue>
using namespace std;
//Undirected graph
//Every vertex of graph contains a list of its adjacent vertices
struct AdjListNode{
	int dest;
	AdjListNode *next;
};

//This struct just stores head of the associated adj lists
struct AdjList{
	AdjListNode *head;
};

class graph
{
	private:
		int V;
		//Array of adjaceny lists 
		AdjList *array; 
	public:
		graph(int v){
			V=v;
			array=new AdjList[V];
			for(int i=0;i<V;++i){
				array[i].head=NULL;
			}
		}
		AdjListNode* newAdjListNode(int dest){
			AdjListNode *newNode= new AdjListNode;
			newNode->next=NULL;
			newNode->dest=dest;
			return newNode;
		}
		void addEdge(int src, int dest){
			//New nodes are added at beginning
			AdjListNode *newNode=newAdjListNode(dest);
			newNode->next=array[src].head;
			array[src].head=newNode;
			newNode=newAdjListNode(src);
			newNode->next=array[dest].head;
			array[dest].head=newNode;
		}
		
		void printGraph(){
			int v;
			for(v=0;v<V;++v){
				cout<<"Adjaceny list of vertex "<<v<<" is: ";
				AdjListNode *crawler=array[v].head;
				while(crawler!=NULL)
				{
					cout<<crawler->dest<<" ";
					crawler=crawler->next;
				}
				cout<<"\n";
				
			}
		}
	void BFS(int s){
		queue<int> q;
		bool *visited=new bool[V];
		for(int i=0;i<V;++i){
			visited[i]=false;
		}
		q.push(s);
		visited[s]=true;
		AdjListNode *i;
		while(!q.empty()){
		s=q.front(); q.pop();
		cout<<s<<" ";
		for(i=array[s].head;i!=NULL;i=i->next)
		{
			if(!visited[i->dest])
			{
				visited[i->dest]=true;
				q.push(i->dest);
			}
		}
		}
		cout<<endl;
		
	}
	void DFS(int v,bool visited[]){
		visited[v]=true;
		cout<<v<<" ";
		AdjListNode *i;
		for(i=array[v].head;i!=NULL;i=i->next)
		{
			if(!visited[i->dest])
			{
				DFS(i->dest,visited);
			}
		}
	}		
	void DFS_wrapper(int v){
		bool *visited=new bool[V];
		for(int i=0;i<V;++i){
			visited[i]=false;
		}
		DFS(v,visited);
	}
};
int main()
{  graph g(7); 
    g.addEdge(0, 2); 
    g.addEdge(0, 1); 
    g.addEdge(1, 4); 
    g.addEdge(1, 3); 
    g.addEdge(2, 6);
	g.addEdge(2,5); 
  
    cout << "Following is Breadth First Traversal of a level order tree with root 0\n"; 
    g.BFS(0); 

    g.printGraph();
    
    return 0;
	
}
