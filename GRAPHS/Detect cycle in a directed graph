
class Solution {
  private:
    bool dfs(int node , vector<int>&vis,vector<int>&pathvis,vector<int> adj[]){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis, pathvis,adj) == true) return true;
            }
            else if(vis[it] && pathvis[it]) return true;
        }
        pathvis[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj)==true) return true;
            }
        }
        
        return false;
    }
};

