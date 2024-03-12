#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent;
    
public:
    //ek constructor bnaya jo rank ke ander starting mei 
    //saare elements ki value 0 and parent mei har element 
    //ki value uske index ke baraber hogi
    DisjointSet(int n){
        
        // yha pe n+1 size isilye liya taki 0 index ya 1 index 
        //graph ho dono ke liye work krega ... 0 index ke liye 
        //0 se n-1 tk jaega but for 1 index 1 se n tk jaega 
        //isiliye n+1 size use kiya 
        
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    //this function gives you the ultimate parent 
    int findUPair(int node){
        //base case
        if(node == parent[node]) return node;
        
        // yha pe hum chahte to direct return findUPair(parent[node]) 
        //bhi likh skte the but return parent[node] = findUPair(parent[node]) pe
        //paret[node] = isiliye lgaya taki recursion baar baar na ho,
        // values store hoti rhe and we can get them in a constant time
        
        return parent[node] = findUPair(parent[node]);
    }
    
    void unionByRank(int u,int v){
        //we are finding the ultimate parent of u and v;
        int ulp_u = findUPair(u);
        int ulp_v = findUPair(v);
        
        //agar dono ke parent equal h to no need to do anything kyuki vo already connected hai
        if(ulp_v == ulp_u) return;
        
        //hum yha pe choti rank ko badi rank se isiliye connect kr rhe 
        //taki complexity na bdhe, agar bade ko chote rank se connect 
        //krenge to choti rank vala ultimate parent hoga and badi rank 
        //ki lenght vaise hi badi h and we are increasing by another 
        //node and vica versa .
        if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] >rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        
        //rank bs tabhi update hogi jb dono ki rank equal 
        //ho kyuki kisi ko bhi kisi se connect ki rank 1 se increase hogi hi
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
        
        
    }
    
};

int main(){
    
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPair(3) == ds.findUPair(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    
    
    
    ds.unionByRank(3, 7);

    if (ds.findUPair(3) == ds.findUPair(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
    
}
    
