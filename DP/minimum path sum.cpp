============================================================================================================================ 
                                                  SIMPLE RICURSION
============================================================================================================================

class Solution {
int f(vector<vector<int>>& grid , int n , int m){
    if(n == 0 && m == 0){
        return grid[0][0];
    }

    if(n < 0 || m <0) return 1e9;

    int up = grid[n][m] + f(grid,n-1,m);
    int down = grid[n][m] + f(grid,n,m-1);

    return min(up,down);
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return f(grid,n-1,m-1);
    }
};
============================================================================================================================ 
                                                   MEMOISATION
============================================================================================================================

class Solution {
int f(vector<vector<int>>& grid , int n , int m , vector<vector<int>>&dp){
    if(n == 0 && m == 0){
        return grid[0][0];
    }

    if(n < 0 || m <0) return 1e9;
    if(dp[n][m] != -1) return dp[n][m];
    int up = grid[n][m] + f(grid , n-1,m,dp);
    int down = grid[n][m] + f(grid , n,m-1,dp);

    return dp[n][m] = min(up,down);
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(grid,n-1,m-1,dp);
    }
};
============================================================================================================================ 
                                                   TABULATION
============================================================================================================================

class Solution {

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i ==0 && j == 0){
                    dp[i][j] = grid[i][j];
                }

                else{
                    int up = grid[i][j];
                    if(i > 0) up += dp[i-1][j];
                    else up += 1e9;
                    int left = grid[i][j];
                    if(j > 0) left += dp[i][j-1];
                    else left += 1e9;

                    dp[i][j] = min(up,left);
                }
            }

        
        }

        return dp[n-1][m-1];
    }
};

============================================================================================================================ 
                              SPACE OPTIMIZATION ( REMOVING DP ARRAY AND USING DIFFERENT VARIABLES )
============================================================================================================================

class Solution {

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>cur(m,0);
            for(int j=0;j<m;j++){
                if(i ==0 && j == 0){
                    cur[j] = grid[i][j];
                }

                else{
                    int up = grid[i][j];
                    //requiring previous row's j coloum 
                    if(i > 0) up += prev[j];
                    else up += 1e9;

                    int left = grid[i][j];
                    //requiring current row's j-1 coloum
                    if(j > 0) left += cur[j-1];
                    else left += 1e9;

                    cur[j] = min(up,left);
                }
            }
            prev = cur;
        
        }

        return prev[m-1];
    }
};
