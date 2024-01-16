//Approch 1
class Solution {
private:

    bool isSafe(int col , vector<string>&board , int row , int n){
        int r = row;
        int c = col;

        //for upper diagonal
        while(col >= 0 && row >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
            row--;
        }

        //for left colums
        row = r;
        col = c;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }

        //for lower diagonal
        row = r;
        col= c;
        while(col >=0 && row <n){
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        }

        return true;
    }

    void solve(int col , vector<string>&board , vector<vector<string>>&ans , int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(col , board , i  , n)){
                board[i][col] = 'Q';
                solve(col+1 , board , ans , n);
                board[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n ,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,board,ans,n);
        return ans;
        
    }
};



//Approch 2
class Solution {
private:
    void solve(int col , vector<vector<string>>&ans, vector<string>&board  , vector<int>&leftCol , vector<int>&upperDiag, vector<int>&lowerDiag , int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(upperDiag[n-1 + col -i] == 0 && leftCol[i] == 0 && lowerDiag[i+col] == 0){
                upperDiag[n-1 + col -i] = 1;
                leftCol[i] = 1;
                lowerDiag[i+col] = 1;
                board[i][col] = 'Q';
                solve(col+1,ans,board,leftCol , upperDiag , lowerDiag ,n);
                board[i][col] = '.';
                upperDiag[n-1 + col -i] = 0;
                leftCol[i] = 0;
                lowerDiag[i+col] = 0;

            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        vector<int>leftCol(n , 0);
        vector<int>upperDiag(2*n-1 , 0);
        vector<int>lowerDiag(2*n-1 , 0);
        string s(n , '.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,ans,board , leftCol , upperDiag , lowerDiag,n);
        return ans;        
    }
};
