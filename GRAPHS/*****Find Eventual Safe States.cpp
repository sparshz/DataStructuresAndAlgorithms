class Solution {
private:
    bool dfs(int i, vector<int>&vis,vector<int>&pathvis,vector<int>&check , vector<int>adj[]){
        vis[i] = 1;
        pathvis[i] = 1;

        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,check,adj)== true){
                    check[it]=0;
                    return true;
                }
            }
            else if(pathvis[it] == 1){
                check[it] = 0;
                return true;
            }
        }

        check[i] = 1;
        pathvis[i] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>adj[n];
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>check(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,check,adj);
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());

        return ans;
        
    }
};
