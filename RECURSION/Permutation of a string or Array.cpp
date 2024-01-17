//Approch one:just swapping every index with first one so that we can start permutaion with evry element 
class Solution {
private:
    void solve(vector<vector<int>>&ans , vector<int>nums , int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index ; i<nums.size();i++){
            swap(nums[index] , nums[i]);
            solve(ans,nums,index+1);
            swap(nums[index] , nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(ans,nums,0);
        return ans;
        
    }
};

//Approch 2: Used an extra space to store the ans
class Solution {
private:
    void solve(vector<int>ds , int vis[] , vector<int>nums, vector<vector<int>>&ans){
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i =0;i<nums.size() ;i++){
            if(!vis[i]){
                ds.push_back(nums[i]);
                vis[i] =1;
                solve(ds,vis,nums,ans);
                ds.pop_back();
                vis[i] =0;
                
            }

        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = nums.size();
        int vis[n] ;
        for(int i=0;i<nums.size();i++){
            vis[i] = 0;
        }
        solve(ds,vis,nums,ans);
        return ans;
    }
};
