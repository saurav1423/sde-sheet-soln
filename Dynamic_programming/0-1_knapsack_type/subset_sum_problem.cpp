// optimal substructure
// overlapping subproblemss

Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

//brute force
bool helper(vector<int> &arr, int sum, int ind){
        
    if(sum == 0){
        return true;
    }
    if(ind == arr.size()){
        return false;
    }
    if(arr[ind]>sum){
        return helper(arr, sum, ind+1);
    }
    else{
        return helper(arr, sum, ind+1) || helper(arr, sum-arr[ind], ind+1);
    }
    
    
}

bool isSubsetSum(vector<int>arr, int sum){
    return helper(arr, sum, 0);
    
}


time - The above solution may try all subsets of given set in worst case. Therefore time complexity of the above solution is exponential.

//now, instead of trying all subset everytime, we can try to store the answer so that we can use it whenever we need it
bool isSubsetSum(vector<int>arr, int sum){
        
    int n = arr.size();
    vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
    
    for(int i=1; i<=sum; i++){
        dp[0][i] = false;
    }
    
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            
            if(arr[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            
        }
    }
    
    return dp[n][sum];
        
}

time - 0(N*sum)
space - 0(N*sum)