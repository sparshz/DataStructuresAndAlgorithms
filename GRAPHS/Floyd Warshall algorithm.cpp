class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9;
	            }
	            if(i == j) matrix[i][j] = 0;
	        }
	    }
	    
	    
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j] = min(matrix[i][j] , (matrix[i][k] + matrix[k][j]));
	            }
	        }
	    }

//if interviewer says if there is negaitve cycle then
    for(int i=0;i<n;i++)
    {
        if(matrix[i][i] < 0 )
        //here we can return what is asked
    }

	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};
