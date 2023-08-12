class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto it:redEdges){
            graph[it[0]].push_back({it[1],0});
        }

        for(auto it:blueEdges){
            graph[it[0]].push_back({it[1],1});
        }

        queue<pair<int,int>>q;
        q.push({0,0}); // for red edge (kyuki self loop bhi ho skta h of both the colors)
        q.push({0,1}); // for blue edge

        vector<vector<int>>dist(n,vector<int>(2,INT_MAX));
        dist[0][0] = 0;
        dist[0][1] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int color = q.front().second;
            q.pop();

            for(auto it:graph[node]){
                if(dist[it.first][it.second] == INT_MAX && color != it.second){
                    dist[it.first][it.second]  = dist[node][color] + 1;
                    q.push({it.first,it.second});
                }
            }
        }

        vector<int>res(n,-1);

        for(int i=0;i<n;i++){
            if(dist[i][0] != INT_MAX || dist[i][1] != INT_MAX){
                res[i] = min(dist[i][0] , dist[i][1]);
            }
        }

        return res;
        
    }
};
