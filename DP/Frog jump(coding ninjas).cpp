============================================================================================================================ 
                                                  SIMPLE RICURSION
============================================================================================================================

#include <bits/stdc++.h> 
int f(int ind  , vector<int>&heights){
    if(ind == 0) return 0;
    int left = f(ind -1 , heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if(ind > 1) right = f(ind -2 , heights) + abs(heights[ind] - heights[ind - 2]);
    

    return  min(left , right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return f(n-1 , heights);
}

============================================================================================================================ 
                                                   MEMOISATION
============================================================================================================================

#include <bits/stdc++.h> 
int f(int ind  , vector<int>&heights , vector<int>&dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int left = f(ind -1 , heights,dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if(ind > 1) right = f(ind -2 , heights,dp) + abs(heights[ind] - heights[ind - 2]);
    return dp[ind] = min(left , right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n+1,-1);
    return f(n,heights,dp);
    
}


============================================================================================================================ 
                                                   TABULATION
============================================================================================================================

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,0);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int fs = dp[i - 1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = dp[i - 2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(fs,ss);
    }
    return dp[n-1];
}

============================================================================================================================ 
                              SPACE OPTIMIZATION ( REMOVING DP ARRAY AND USING DIFFERENT VARIABLES )
============================================================================================================================

#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,0);
    // dp[0] = 0;
    int previ = 0;
    int previ2 = 0;
    int curr = 0;
    for(int i=1;i<n;i++){
        int fs = previ + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = previ2 + abs(heights[i] - heights[i-2]);
        curr = min(fs,ss);
        previ2 = previ;
        previ = curr;
    }
    return previ;
}
