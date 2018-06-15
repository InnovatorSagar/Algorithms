#include <bits/stdc++.h>
using namespace std;
class Graph{
	int ve;
	vector<int> *adj;
	public:
	Graph(int v)
	{
		ve=v;
		adj = new vector<int>[ve];
	}
	
	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool isCyclic()
	{
		vector<bool> visited(ve,false);
		//vector<bool> recStack(ve,false);
		for(int i=0;i<ve;i++)
		if(!visited[i])
		if(isCycleUntil(i,visited,-1))
		return true;
		return false;
	}
		
	bool isCycleUntil(int i , vector<bool>& visited, int parent)
	{
		visited[i]=true;
		for(int j=0;j<adj[i].size();j++)
		{
		//cout<<"Now at target "<<adj[i][j]<<" "<<parent<<endl;
			if(!visited[adj[i][j]])
			{if(isCycleUntil(adj[i][j],visited,i))
			return true;
			}
			else if(adj[i][j]!=parent)
			return true;
		}
		return false;
	}
};
int main() {
	// your code goes here
    int n,m;//number of vertices and edges respectively
    cin>>n>>m;
     Graph g(n);
     //Enter the edges
     while(m--)
     {
     	int a,b;
     	cin>>a>>b;
     	g.addEdge(a,b);
     }
     
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
	return 0;
}
