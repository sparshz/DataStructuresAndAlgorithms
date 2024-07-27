============================================================================================================================ 
                                                  SIMPLE RICURSION
============================================================================================================================

class Solution {

    int f(int m,int n ){
        if(m == 0 && n == 0){
            return 1;
        }
        if(m < 0 || n <0){
            return 0;
        }

        int up = f(m-1,n);
        int left = f(m,n-1);

        return  up + left;
    }
public:

    int uniquePaths(int m, int n) {
  
        return f(m-1,n-1);
    }
};

============================================================================================================================ 
                                                   MEMOISATION
============================================================================================================================

class Solution {

    int f(int m,int n , vector<vector<int>>&dp){
        if(m == 0 && n == 0){
            return 1;
        }
        if(m < 0 || n <0){
            return 0;
        }

        if(dp[m][n] != -1) return dp[m][n];

        int up = f(m-1,n,dp);
        int left = f(m,n-1,dp);

        return dp[m][n] = up + left;
    }
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
};

============================================================================================================================ 
                                                   TABULATION
============================================================================================================================

class Solution {

public:

    int uniquePaths(int m, int n) {
        int dp[m][n];

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i ==0 && j==0) dp[i][j] = 1;
                else{
                    int up = 0;
                    int down = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) down = dp[i][j-1];
                    dp[i][j] = up + down;
                }
            }

        }

        return dp[m-1][n-1];
    }
};

============================================================================================================================ 
                              SPACE OPTIMIZATION ( REMOVING DP ARRAY AND USING DIFFERENT VARIABLES )
============================================================================================================================

class Solution {

public:

    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);

        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j = 0;j<n;j++){
                if(i ==0 && j==0) curr[j] = 1;
                else{
                    int up = 0;
                    int down = 0;
                    if(i>0) up = prev[j];
                    if(j>0) down = curr[j-1];
                    curr[j] = up + down;
                }
            }
            prev = curr;

        }

        return prev[n-1];
    }
};
