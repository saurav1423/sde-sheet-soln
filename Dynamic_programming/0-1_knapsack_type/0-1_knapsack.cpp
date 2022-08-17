Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken one number of times.

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
        return max(knapSack(N-1, W, val, wt), val[N-1] + knapSack(N-1, W-wt[N-1], val, wt));
}

time - 2^N
                       K(n, W)
                       K(3, 2)  
                   /            \ 
                 /                \               
            K(2, 2)                  K(2, 1)
          /       \                  /    \ 
        /           \              /        \
       K(1, 2)      K(1, 1)        K(1, 1)     K(1, 0)
       /  \         /   \              /        \
     /      \     /       \          /            \
K(0, 2)  K(0, 1)  K(0, 1)  K(0, 0)  K(0, 1)   K(0, 0)
Recursion tree for Knapsack capacity 2 
units and 3 items of 1 unit weight.

//Memoization
int helper(int N, int W, int val[], int wt[], vector<vector<int>> &dp){
    if(N == 0 || W == 0)
        return 0;
        
    if(dp[W][N] != -1)
        return dp[W][N];
    
    else if(W<wt[N-1])
        return dp[W][N] = helper(N-1, W, val, wt, dp);
    
    else
        return dp[W][N] = max(helper(N-1, W, val, wt, dp), val[N-1] + helper(N-1, W-wt[N-1], val, wt, dp));
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(W+1, vector<int> (N+1, -1));
    return helper(N, W, val, wt, dp);   
}

Time Complexity: O(N*W)
Space Complexity: O(N*W) + O(N)

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
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
        }
    }
    
    return dp[N][W];
    
}

Time Complexity: O(N*W)
Space Complexity: O(N*W) + O(N)


//using 1D space
Note that we use 1D array here which is different from classical knapsack where we used 2D array. 
Here number of items never changes. We always have all items available.
int knapSack(int W, int wt[], int val[], int n)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
 
            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}
Time Complexity: O(W*N) where W is the total weight(capacity) and N is the total number of items.
Auxiliary Space: O(W) where W is the total weight.