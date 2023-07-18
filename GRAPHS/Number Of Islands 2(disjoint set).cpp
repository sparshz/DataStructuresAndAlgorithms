

class DisjointSet
{
	
	vector<int>size,parent;
public:
	DisjointSet(int n){
		size.resize(n+1);
		parent.resize(n+1);
		for(int i =0;i<n;i++){
			parent[i]=i;
			size[i]=1;
		}
	}
	
	int findUParent(int node){
		if(node == parent[node]) return node;
		return parent[node] = findUParent(parent[node]);
	}
	
	void unionBySize(int u,int v){
		int ulp_u = findUParent(u);
		int ulp_v = findUParent(v);
		
		if(ulp_v == ulp_u) return;
		
		if(size[ulp_v] < size[ulp_u]){
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
		
		else{
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
	}

	
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>ans;
        int cnt = 0;
        
        for(auto it:operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int adjr = row + dr[i];
                int adjc = col + dc[i];
                if(adjr >=0 && adjr <n && adjc >=0 && adjc <m){
                    if(vis[adjr][adjc] == 1){
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        if(ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo)){
                            ds.unionBySize(nodeNo,adjNodeNo);
                            cnt--;
                        }
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        return ans;
    }
};

