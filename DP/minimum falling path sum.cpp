============================================================================================================================ 
                                                  SIMPLE RICURSION
============================================================================================================================

class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>>& matrix){
        int  m =matrix[0].size();
        if(j<0 || j>m-1) return 1e9;
        if(i==0) return matrix[i][j];
   
        
        int st = matrix[i][j] + solve(i-1,j,matrix);
        int ld = matrix[i][j] + solve(i-1,j+1,matrix);
        int rd = matrix[i][j] + solve(i-1,j-1,matrix);
        
        return min(st,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans=1e9;
        for(int j=0;j<m;j++){
            ans=min(ans,solve(n-1,j,matrix));
        }
        return ans;
    }
};
============================================================================================================================ 
                                                   MEMOISATION
============================================================================================================================

class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int  m =matrix[0].size();
        if(j<0 || j>m-1) return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int st = matrix[i][j] + solve(i-1,j,matrix,dp);
        int ld = matrix[i][j] + solve(i-1,j+1,matrix,dp);
        int rd = matrix[i][j] + solve(i-1,j-1,matrix,dp);
        
        return dp[i][j] = min(st,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=1e9;
        for(int j=0;j<m;j++){
            ans=min(ans,solve(n-1,j,matrix,dp));
        }
        return ans;
    }
};
============================================================================================================================ 
                                                   TABULATION
============================================================================================================================

class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        int ans = 1e9;
        

        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++) dp[0][j] = matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j] +dp[i-1][j];
                int lcor = matrix[i][j];
                if(j-1 >= 0)   lcor += dp[i-1][j-1] ;
                else lcor += 1e8;
                int rcor = matrix[i][j];
                if(j+1 <m)  rcor += dp[i-1][j+1]; 
                else rcor += 1e8;
                dp[i][j] =  min(up , min(lcor,rcor));
            }
        }
        for(int j=0;j<m;j++){
            
            ans = min(ans,dp[n-1][j]);
        }

        

        return ans;
    }
};



============================================================================================================================ 
                              SPACE OPTIMIZATION ( REMOVING DP ARRAY AND USING DIFFERENT VARIABLES )
============================================================================================================================

class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        int ans = 1e9;
        

        vector<int>prev(m,0) , curr(m,0);
        for(int j=0;j<m;j++) prev[j] = matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j] +prev[j];
                int lcor = matrix[i][j];
                if(j-1 >= 0)   lcor += prev[j-1] ;
                else lcor += 1e8;
                int rcor = matrix[i][j];
                if(j+1 <m)  rcor += prev[j+1]; 
                else rcor += 1e8;
                curr[j] =  min(up , min(lcor,rcor));
            }
            prev = curr;
        }
        for(int j=0;j<m;j++){
            
            ans = min(ans,prev[j]);
        }

        

        return ans;
    }
};


