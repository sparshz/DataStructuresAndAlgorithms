class Solution {
private:
    void check(int index , int target , vector<vector<int>>& ans , vector<int>temp,vector<int>&candidates ,int sum){

            if(target == sum){
            ans.push_back(temp);
             return; 
            }
            if(index == candidates.size() || sum > target){
                return;
            }
             
     

        temp.push_back(candidates[index]);
        check(index , target,ans,temp,candidates , sum + candidates[index]);
        temp.pop_back();
        check(index+1,target , ans,temp,candidates , sum);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int>temp;

        check(0,target ,ans , temp ,candidates,0);

        return ans;
        
    }
};
