
#include<bits/stdc++.h>
using namespace std;

void adjlist(vector<int>adj[], int s , int d )
{
	adj[s].push_back(d);
	adj[d].push_back(s);
	
}

void printList(vector<int>adj[] , int v)
{
	for(int i=0;i<v;i++){
		cout<<i<<"->";
		for(auto it:adj[i])
		{
			cout<<it<<",";
		}
		cout<<endl;
	}
}

void bfs(vector<int>adj[] , int v , vector<int>&bfsa)
{
	
	queue<int>q;
	q.push(0);
	int vis[6] = {0};
	
	while(!q.empty())
	{
		int node = 	q.front();
		q.pop();
		bfsa.push_back(node);
		vis[node]=1;
		for(auto it:adj[node])
		{
			if(!vis[it])
			{
				q.push(it);
				vis[it]=1;
			}
		}
	}
	
}

void dfs(vector<int>adj[] , int node, vector<int>&visited , vector<int>&dfsa)
{
	
	dfsa.push_back(node);
	visited[node] = 1;
	for(auto it:adj[node])
	{
		if(!visited[it])
		{
			dfs(adj,it,visited,dfsa);
		}
	}
	
	
}

int main()
{
	int v = 6;
	vector<int> adj[v];
	
		
	adjlist(adj, 0,4);
	adjlist(adj, 4,2);
	adjlist(adj, 4,1);
	adjlist(adj, 2,3);
	adjlist(adj, 3,5);
	adjlist(adj, 3,2);
	adjlist(adj, 5,1);

	
	printList(adj,v);
	
	
	//bfs......................................................
	vector<int>bfsResult;
	bfs(adj,v,bfsResult);
	int size = bfsResult.size();
	cout<<"bfs: ";
	for(int i=0;i<size;i++)
	{
		cout<<bfsResult[i]<<",";
	}
	cout<<endl;
	
	// dfs......................................................
	vector<int>dfsResult;
	vector<int>vis(v,0);
	dfs(adj,0,vis,dfsResult);
	int sizedfsResult = dfsResult.size();
	cout<<"dfs: ";
	for(int i=0;i<sizedfsResult;i++)
	{
		cout<<dfsResult[i]<<",";
	}
	
}
