#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
	
	vector<int>size,parent;
public:
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


int main(){
	
	
	DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    
    if(ds.findUParent(1)  == ds.findUParent(5) ){
    	cout<<"same";
    }
    else cout<<"not same";
	
	ds.unionBySize(3, 7);

	if(ds.findUParent(1)  == ds.findUParent(5) ){
    	cout<<"same";
    }
    else cout<<"not same";
	
	
}
