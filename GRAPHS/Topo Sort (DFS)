
class Solution
{
    private:
    void dfs(int node, vector<int>adj[],stack<int>&s,vector<int>&vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it])
                dfs(it,adj,s,vis);
        }
        s.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>s;
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	            dfs(i,adj,s,vis);
	     
	    }
	    vector<int>ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};

