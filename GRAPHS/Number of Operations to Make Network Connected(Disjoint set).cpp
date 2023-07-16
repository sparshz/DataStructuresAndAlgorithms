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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdge = 0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUParent(u)==ds.findUParent(v)){
                extraEdge++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        int nc = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) nc++;
        }

        int ans = nc-1;
				if(extraEdge >= ans) return ans;
				return -1;
        
    }
};
