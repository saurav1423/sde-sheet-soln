GFG have question where only row and column is sorted but there is no relation between i-1 row last element and i row first element
Whereas in Leetcode question i-1 row last element is always less than i row first element

//brute force approach
we will lineraly traverse the matrix and find the given number
time - 0(N*M) space - 0(1)

//better solution
As every row is sorted so we can apply binary search in every row and search for our target
time - 0(N*logM)

//optimal for gfg and better for leetcode
we will stand at last element of first row and move down if given number is greater than present number or move left if given number
is smaller than present number

int i = 0, j = m-1;

while(i<n && j>=0){
    if(mat[i][j] == target)
       return mat[i][j];
    if(mat[i][j] > target)
       j--;
    else
       i++;      
}

time - 0(N+M)

//optimal for leetcode
we will apply binary search on whole matrix

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int lo = 0;
        int hi = (matrix.size() * matrix[0].size()) - 1;
        int totalColumn = matrix[0].size();

        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/totalColumn][mid % totalColumn] == target) {
                return true;
            }
            if(matrix[mid/totalColumn][mid % totalColumn] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
time - 0(logN*M)    