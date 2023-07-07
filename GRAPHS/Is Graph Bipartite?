==========================================================================================================================================
                                                            USING BFS
==========================================================================================================================================


class Solution {
private:

    bool check(int start,int color[],vector<int>adj[]){
        color[start] = 0;
        queue<int>q;
        q.push(start);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]) return false;
            }
        }
        return true;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        int m = graph[0].size();

        int color[n];
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }

        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                adj[i].push_back(it);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(color[i] == -1)
            {
                if(check(i,color,adj)==false) return false;
            }
        }
        return true;
        
    }
};


==========================================================================================================================================
                                                            USING DFS
==========================================================================================================================================


class Solution {
private:
    bool dfs(int node , vector<int>&color,int c,vector<int> adj[]){
        color[node] = c;
        for(auto it:adj[node]){
            if(color[it] == -1 ){
                if(dfs(it,color,!c,adj)==false) return false;
            }
            else if(color[it] == color[node]) return false;
            
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<int>adj[n];
        for(int i =0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
                adj[it].push_back(i);
            }
        }
        
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1)
                if(dfs(i,color,0,adj)== false) return false;
        }

        return true;
        
    }
};
