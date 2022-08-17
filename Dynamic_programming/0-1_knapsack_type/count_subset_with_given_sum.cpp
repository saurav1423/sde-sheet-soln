Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}


//brute
int mod = 1e9+7;
	
int perfectSum(int arr[], int n, int sum)
{
        if(n == 0){
        if(sum == 0)
            return 1;
        else
            return 0;
    }
    
    
        if(arr[n-1]>sum)
        return perfectSum(arr, n-1, sum)%mod;
        else
        return perfectSum(arr, n-1, sum-arr[n-1])%mod + perfectSum(arr, n-1, sum)%mod;
}

time - exponential


//optimal
int mod = 1e9+7;
int helper(vector<vector<int>> &dp, int arr[], int n, int sum){
    
    if(n == 0){
        if(sum == 0)
        return 1;
        else
        return 0;
    }
    
    if(dp[n][sum] != -1)
    return dp[n][sum]%mod;

    if(arr[n-1]>sum)
        return dp[n][sum] = helper(dp,arr, n-1, sum)%mod;
    else
        return dp[n][sum] = helper(dp, arr, n-1, sum-arr[n-1])%mod + helper(dp, arr, n-1, sum)%mod;
        
    
}

int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
    return helper(dp, arr, n, sum)%mod;
}

time - 0(N*sum)
space - 0(N*sum)