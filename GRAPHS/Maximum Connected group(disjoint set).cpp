
class DisjointSet
{
public:
    vector<int>size,parent;
    
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
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        //step 1 :- read in notes
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int ind = 0; ind <4;ind++){
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1){
                        int node = i*n +j;
                        int adjNode = newr *n + newc;
                        ds.unionBySize(node , adjNode);
                    }
                }
            }
        }
        
        //step 2 :- read in notes
        int mx = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                set<int>s;
                for(int ind = 0;ind<4;ind++){
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];
                    
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1){
                        s.insert(ds.findUParent(newr*n + newc));
                    }
                }
                
                int sum = 0;
                for(auto it:s){
                    sum+=ds.size[it];
                }
                
                mx = max(mx,sum+1);
            }
        }
        //edge case :- read in notes
        for(int i=0;i<n*n;i++){
            mx = max(mx,ds.size[ds.findUParent(i)]);
        }
        
        
        return mx;
        
    }
};

