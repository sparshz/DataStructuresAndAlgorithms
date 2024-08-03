============================================================================================================================ 
                                                  SIMPLE RICURSION
============================================================================================================================

class Solution
{
    private:
    int f(int W, int wt[], int val[], int i ){
        
        if(i == 0){
            if(wt[0] <= W ){
                return val[0];
            }
            else return 0;
        }
        
        int notTake = 0 + f(W,wt,val,i-1);
        int take = INT_MIN;
        if(wt[i] <= W){
            take = val[i] + f(W - wt[i] , wt,val,i-1);
        }
        
        return  max(notTake,take);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return f(W,wt,val,n-1);
    }
};
============================================================================================================================ 
                                                   MEMOISATION
============================================================================================================================
class Solution
{
    private:
    int f(int W, int wt[], int val[], int i , vector<vector<int>>&dp ){
        
        if(i == 0){
            if(wt[0] <= W ){
                return val[0];
            }
            else return 0;
        }
        
        if(dp[i][W] != -1) return dp[i][W];
        
        
        int notTake = 0 + f(W,wt,val,i-1,dp);
        int take = INT_MIN;
        if(wt[i] <= W){
            take = val[i] + f(W - wt[i] , wt,val,i-1,dp);
        }
        
        return dp[i][W] = max(notTake,take);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n , vector<int>(W+1,-1));
       return f(W,wt,val,n-1,dp);
    }
};
  
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

class Solution
{

    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n , vector<int>(W+1,0));
        for(int i = wt[0] ;i <= W ;i++) dp[0][i] = val[0];
        
        for(int i=1;i<n;i++){
            for(int w = 0 ; w <= W;w++){
                
                int notTake = 0 + dp[i-1][w];
                int take = INT_MIN;
                if(wt[i] <= w){
                    take = val[i] + dp[i-1][w - wt[i]];
                }
                
                 dp[i][w] = max(notTake,take);
            }
        }
        
       return dp[n-1][W];
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
