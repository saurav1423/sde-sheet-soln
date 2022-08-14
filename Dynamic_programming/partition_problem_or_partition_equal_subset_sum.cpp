// optimal substructure
// overlapping subproblems


Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the 
sum of elements in both subsets is equal.

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].


//brute force(recursive)
 bool helper(vector<int> arr, int sum, int ind){
        
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

bool canPartition(vector<int>& nums) {
    
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
        sum += nums[i];
    
    if(sum%2 == 1)
        return false;
    
    return helper(nums, sum/2, 0);
    
}

//dp

bool canPartition(vector<int>& nums) {
        
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
        sum += nums[i];
    if(sum%2 == 1)
        return false;
    sum = sum/2;
    
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
    
    for(int i=1; i<=sum; i++){
        dp[0][i] = false;
    }
    
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            
            if(nums[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
            
        }
    }
    
    return dp[n][sum];
    
}