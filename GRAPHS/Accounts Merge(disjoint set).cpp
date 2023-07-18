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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        //map create kiya h jo store krega mails and their original index on which they are present
        map<string,int>mapMailNode;

        for(int i=0;i<n;i++){
            // j=1 se isiliye shuru kr rhe h kyuki j =0 pe name hai and we just need to store mails jo index 1 se shuru hai
            for(int j=1;j<accounts[i].size();j++){
                //agar map mei mail nahi milti h to map end pe point kr dega us time we have to make th entry of the mail with its otiginal index
                if(mapMailNode.find(accounts[i][j]) == mapMailNode.end()){
                    mapMailNode[accounts[i][j]] = i;
                }
                //agar map mei mail mil jati hai matlb vo mail koi or bhi use kr rha h that means the person is same so abhi current index ko union krdo us mail ke index ke sath jo already map mei storded hai
                else{
                    ds.unionBySize(i,mapMailNode[accounts[i][j]]);
                }

            }
        }

        //make a merge vector jo saari mails store krega but on their correct or can say updated index
        vector<string>merge[n];
        
        for(auto it:mapMailNode){
            string mail = it.first;
            //yha pe mail apne ultimate parent ke index pe store ho rhi hai
            int node = ds.findUParent(it.second);
            merge[node].push_back(mail);
        }
        

         vector<vector<string>>ans;

         for(int i=0;i<n;i++){
             //it is also possible ki index pe koi mail hai hi nahi jo mail thi vo apne ultimate parent index se attach ho gai ho so that particular index becomes empty
             if(merge[i].size() == 0) continue;

            //as we have to return the mails in the sorted manner with the owner naeme
             sort(merge[i].begin(),merge[i].end());

             // temp will store all the mails at a particular index and then the full temp vector will be store in ans vector
             vector<string>temp;
             //as we have to return name and then its mail so at index [i][0] the name is there to phele name push kiya temp mei
             temp.push_back(accounts[i][0]);
             // name ke baad merge ke ith index pe jitne sorted mails h sb temp mei daal di
             for(auto it:merge[i]){
                 temp.push_back(it);
             }


             ans.push_back(temp);
         }


        return ans;

        
        
    }
};
