
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{source.first,source.second}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        if(source.first == destination.first && source.second == destination.second){
            return 0;
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nc >= 0 && nc < m && nr >= 0 && nr <n && grid[nr][nc] == 1 && dis + 1 < dist[nr][nc]){
                    dist[nr][nc] = dis + 1;
                    q.push({dis + 1 ,{nr,nc}});
                    if(nr == destination.first && nc == destination.second) return dis +1;
                }
            }
        }
        
        return -1;
    }
};


