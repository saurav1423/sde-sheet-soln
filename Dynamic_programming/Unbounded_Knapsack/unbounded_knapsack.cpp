Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explanation: 
    1.Pick the 2nd element thrice.
    2.Total profit = 1 + 1 + 1 = 3. Also the total 
    weight = 1 + 1 + 1  = 3 which is <= W.

//recursion
int knapSack(int N, int W, int val[], int wt[])
{
    if(N == 0 || W == 0)
        return 0;
    
    else if(W<wt[N-1])
        return knapSack(N-1, W, val, wt);
    
    else
        return max(knapSack(N-1, W, val, wt), val[N-1] + knapSack(N, W-wt[N-1], val, wt));
}

//Memoization
int helper(int N, int W, int val[], int wt[], vector<vector<int>> &dp){
    if(N == 0 || W == 0)
        return 0;
        
    if(dp[W][N] != -1)
        return dp[W][N];
    
    else if(W<wt[N-1])
        return dp[W][N] = helper(N-1, W, val, wt, dp);
    
    else
        return dp[W][N] = max(helper(N-1, W, val, wt, dp), val[N-1] + helper(N, W-wt[N-1], val, wt, dp));
}

Time Complexity: O(N*W)
Space Complexity: O(N*W) + O(N)

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(W+1, vector<int> (N+1, -1));
    return helper(N, W, val, wt, dp);   
}

//tabular
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N+1, vector<int> (W+1, -1));
    
    for(int i=0; i<=N; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            
            else if(j<wt[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i][j-wt[i-1]]);
        }
    }
    
    return dp[N][W];
    
}

Time Complexity: O(N*W)
Space Complexity: O(N*W) + O(N)


//using 1D space
Note that we use 1D array here which is different from classical knapsack where we used 2D array. 
Here number of items never changes. We always have all items available.
int unboundedKnapsack(int W, int n, int val[], int wt[])
{
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    int dp[W+1];
    memset(dp, 0, sizeof dp);
 
    // Fill dp[] using above recursive formula
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
 
    return dp[W];
}

Time Complexity: O(W*N) where W is the total weight(capacity) and N is the total number of items.
Auxiliary Space: O(W) where W is the total weight.