class DisjointSet{
    vector<int>size,parent;
public:
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i] = 1;
        }  
    }

    int findP(int node)
        {
            if(node == parent[node]) return node;
            return parent[node] = findP(parent[node]);
        }

        void unionBySize(int u,int v){
            int upu = findP(u);
            int upv = findP(v);
            if(upu == upv) return;
            if(size[upu] < size[upv]){
                parent[upu] = upv;
                size[upv]+= size[upu];
            }

            else
            {
                parent[upv] = upu;
                size[upu]+= size[upv];
            }

        }

};



class Solution {

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i,j);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(ds.findP(i) == i){
                cnt++;
            }
        }

        return cnt;

        
    }
};
