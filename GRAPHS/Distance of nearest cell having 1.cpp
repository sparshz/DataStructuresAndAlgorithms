vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>dis(n,vector<int>(m,0));
	    //{{row,col},strps}
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                vis[i][j] =1;
	                q.push({{i,j},0});
	            }
	            
	        }
	        
	    }
	    
	    int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[r][c] = steps;
            
            for(int i=0;i<4;i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >=0 && nrow <n && ncol >=0 && ncol <m && grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                    vis[nrow][ncol] =1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        
        return dis;
        
        
	}
