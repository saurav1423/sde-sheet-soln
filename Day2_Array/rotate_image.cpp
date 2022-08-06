You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

eg - 1   2   3           7   4   1
     4   5   6    ---->  8   5   2 
     7   8   9           9   6   3

//brtue force approach
take one matrix of same size and just place the element as required

//optimal 
rather than using extra space, we will do it in place

void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
