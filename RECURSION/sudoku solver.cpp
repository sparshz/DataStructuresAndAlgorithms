class Solution {
bool solve(vector<vector<char>>&board){
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j = 0; j< m ; j++){
                if(board[i][j] == '.'){
                    for(char k = '1' ; k<='9';k++){
                        if(isValid(k,board,i,j)){
                            board[i][j] = k;
                            if(solve(board) == true) return true;
                            else board[i][j] = '.';
                            
                        }

                    }
                    return false;
                }
                
            }
        }
        return true;
    }


    bool isValid (char num , vector<vector<char>>&board , int row, int col){
        for(int i=0;i<9;i++){
            //check for row
            if(board[i][col] == num) return false;

            //check for col
            if(board[row][i] == num) return false;

            //check for interenal block
            if(board[3*(row/3) + (i/3)][3 * (col/3) + (i%3)] == num) return false;

            
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    

    
};
