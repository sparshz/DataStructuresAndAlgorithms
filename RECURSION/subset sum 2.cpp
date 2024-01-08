class Solution {
private:
    void solve(int index , vector<int>&nums , set<vector<int>>&s , vector<int>&temp){
        if(index >= nums.size()){
            s.insert(temp);
            return;
        }

        temp.push_back(nums[index]);
        solve(index + 1 , nums , s , temp);
        temp.pop_back();
        solve(index + 1 , nums , s , temp);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>temp;

        solve(0,nums,s , temp);
        for(auto it:s){
            ans.push_back(it);
        }

        return ans;
        
    }
};
