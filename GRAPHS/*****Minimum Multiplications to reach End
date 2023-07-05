

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        if(start == end) return 0;
        //{steps,node}
        queue<pair<int,int>>q;
        q.push({0,start});
        vector<int>dist(100000,1e9);
        int mod = 100000;
        dist[start] = 0;
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            for(int i=0;i<n;i++){
                int mul = (node * arr[i])%mod;
                if(steps +1 < dist[mul]){
                    dist[mul] = steps +1;
                    if(mul == end) return steps +1;
                    q.push({steps+1,mul});
                }
            }
            
        }
        
        return -1;
        
    }
};

