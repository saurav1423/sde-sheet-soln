There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to 
move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

//brute force
recursion

int helper(int m, int n, int i, int j){
        if(i == m-1 && j == n-1)
            return 1;
        if(i>m-1 || j>n-1)
            return 0;
        
        return helper(m, n, i+1, j) + helper(m, n, i, j+1);
    }
    
    
    int uniquePaths(int m, int n) {
        
        return helper(m, n, 0, 0);
        
    }
time - exponential 0(2^n)    

//better(memoization)

int helper(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1)
            return 1;
        if(i>m-1 || j>n-1)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = helper(m, n, i+1, j, dp) + helper(m, n, i, j+1, dp);
    }
    
    
int uniquePaths(int m, int n) {
        
    vector<vector<int>> dp(m, vector<int> (n, -1));
    return helper(m, n, 0, 0, dp);
        
}

time - 0(M*N)  space - 0(M*N)

//optimal
question can be solved using combinations logic
see, we are at (0,0) and want to reach (m-1,n-1) and we can move either right or down.
so to reach at destination we must take (n-1) right move and (m-1) down move {think by an example, very easy thing}

so lets take an example, we have m = 2 and n = 3
means we have to take 1 down and 2 right step to reach at destination

ans can be 
RRD,  RDR,  DRR

means (m-1)+(n-1)Cn-1 or (m-1)+(n-1)Cm-1

int uniquePaths(int m, int n) {
        
        int N = m + n - 2;
        int r = m - 1;
        double res = 1;
        
        for(int i=1; i<=r; i++)
            res = res*(N-r+i)/i;
        
        return (int)res;
        
    }

time - 0(M-1) or 0(N-1) whether u use (m-1)+(n-1)Cm-1 or (m-1)+(n-1)Cn-1     
space - 0(1)