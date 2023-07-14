


    bool bfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        //{node,parent}
        queue<pair<int,int>>q;
        q.push({node,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(parent != it) return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(bfs(i,vis,adj)==true) return true;
            }
        }
        return false;
    }
