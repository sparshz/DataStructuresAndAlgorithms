
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        int mod = (int)(1e9 + 7);
        vector<long long>dist(n, 1e15);
        dist[0]=0;
        vector<long long>ways(n,0);
        ways[0] = 1;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
        q.push({0,0});
        while(!q.empty()){
            long long dis = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it:adj[node]){
                int adjnode = it.first;
                long long edw = it.second;

                //it means we are comming first time at this node with the short distance 
                if(dist[adjnode] > dis + edw){
                    dist[adjnode] = dis +edw;
                    q.push({dis+edw,adjnode});
                    ways[adjnode] = ways[node];
                }

                //it means we have already arived the node before with the same distance but from another path so the total ways 
                // will be the ways that previously there + the new ways
                else if(dist[adjnode] == dis + edw){
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};
