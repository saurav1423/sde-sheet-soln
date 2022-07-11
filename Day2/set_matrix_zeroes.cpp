question
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

first ask the interviewer that is all element present in the matrix is >=0 as we are going to use that thing

//brute force approach
traverse the matrix and whenever you encounter 0, traverse for row and column for that 0 and set element to -1,
dont change 0 to -1in that row or column as we can miss 0. After traversing whole matrix, again traverse it and change all -1 to 0.

time - 0(N*M)[for traversing matrix] * 0(N + M)[to traverse row and column of that 0]
space - 0(1)

//better
we will take two array, one of size of row and other of size of column.
we will store 0 when we encounter and then using that we will change matrix.

void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int> row_arr(row, -1);
        vector<int> col_arr(col, -1);
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0 ){
                    row_arr[i] = 0;
                    col_arr[j] = 0;
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(row_arr[i] == 0 || col_arr[j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        
    }

//optimal
without using any space, we will use first row and first column as our array

void setZeroes(vector<vector<int>>& matrix) {
        
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        
        for(int i=0; i<rows; i++){
            
            if(matrix[i][0] == 0)col0 = 0;
            
            for(int j=1; j<cols; j++){
                
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=rows-1; i>=0; i--){
            for(int j=cols-1; j>=1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            
            if(col0 == 0)matrix[i][0] = 0;
        }
        
    }    