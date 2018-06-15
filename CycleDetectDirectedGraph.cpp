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
	}

	bool isCyclic()
	{
		vector<bool> visited(ve,false);
		vector<bool> recStack(ve,false);
		for(int i=0;i<ve;i++)
		if(isCycleUntil(i,visited,recStack))
		return true;
		return false;
	}
		
	bool isCycleUntil(int i , vector<bool> visited, vector<bool> recStack)
	{
		if(!visited[i])
		{visited[i] = true;
		recStack[i]=true;
			for(int j=0;j<adj[i].size();j++)
			if(!visited[adj[i][j]]&&isCycleUntil(adj[i][j],visited,recStack))
			return true;
			else if (recStack[adj[i][j]])
			return true;
		}
		recStack[i] = false;
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
