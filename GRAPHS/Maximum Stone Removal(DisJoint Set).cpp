
class DisjointSet
{
    
    
public:
    vector<int>size,parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i =0;i<=n;i++){
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it:stones){
            maxRow = max(maxRow , it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow + maxCol +1);
        unordered_map<int,int>stoneNodes;
        
        for(auto it:stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow +1;
            ds.unionBySize(nodeRow , nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        
        int cnt = 0;
        for(auto it:stoneNodes){
            if(ds.findUParent(it.first) == it.first){
                cnt++;
            }
        }
        
        return n - cnt;
    }
};

