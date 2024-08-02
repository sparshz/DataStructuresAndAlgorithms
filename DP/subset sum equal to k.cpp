============================================================================================================================ 
                                                  SIMPLE RICURSION
============================================================================================================================

#include <bits/stdc++.h> 
bool f(int i,int target,vector<int>&arr){
    if(target == 0) return true;
    if(i == 0) return (arr[0] == target);

    int notTake = f(i-1 , target , arr);
    int take = false;
    if(target >= arr[i]){
        take = f(i-1 , target - arr[i] , arr); 
    }

    return take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    return f(n-1,k,arr);
}
============================================================================================================================ 
                                                   MEMOISATION
============================================================================================================================

#include <bits/stdc++.h> 
bool f(int i,int target,vector<int>&arr , vector<vector<int>>&dp){
    if(target == 0) return true;
    if(i == 0) return (arr[0] == target);

    if(dp[i][target] != -1) return dp[i][target];
    int notTake = f(i-1 , target , arr,dp);
    int take = false;
    if(target >= arr[i]){
        take = f(i-1 , target - arr[i] , arr,dp); 
    }

    return dp[i][target] =  take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}
============================================================================================================================ 
                                                   TABULATION
============================================================================================================================
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));

    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int target = 1; target<=k;target++){
            bool notTake = dp[i-1][target];
            bool take = false;
            if(target >= arr[i]){
                take = dp[i-1][target - arr[i]]; 
            } 
            dp[i][target] = take || notTake;
        }
    }

    return dp[n-1][k];
    
}


============================================================================================================================ 
                              SPACE OPTIMIZATION ( REMOVING DP ARRAY AND USING DIFFERENT VARIABLES )
============================================================================================================================

#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k+1,0) , curr(k+1,0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int target = 1; target<=k;target++){
            bool notTake = prev[target];
            bool take = false;
            if(target >= arr[i]){
                take = prev[target - arr[i]]; 
            } 
            curr[target] = take || notTake;
        }
        prev = curr;
    }

    return prev[k];
    
}
