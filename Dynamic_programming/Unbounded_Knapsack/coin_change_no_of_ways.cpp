Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.
Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

//brute force
long long int count(int s[], int m, int n) {
        
    if(n == 0)
        return 1;
    if(m == 0)
        return 0;
    if(s[m-1]<=n)
        return count(s, m, n-s[m-1]) + count(s, m-1, n);
    else
        return count(s, m-1, n);

}

time - 0(2^n)

                            C({1,2,3}, 5)                     
                           /             \    
                         /                 \                  
             C({1,2,3}, 2)                 C({1,2}, 5)
            /       \                      /      \         
           /         \                    /         \   
C({1,2,3}, -1)  C({1,2}, 2)        C({1,2}, 3)    C({1}, 5)
               /    \             /     \           /     \
             /       \           /       \         /        \
    C({1,2},0)  C({1},2)   C({1,2},1) C({1},3)    C({1}, 4)  C({}, 5)
                   / \     / \        /\         /     \         
                  /   \   /   \     /   \       /       \  
                .      .  .     .   .     .   C({1}, 3) C({}, 4)
                                               / \ 
                                              /   \   
The function C({1}, 3) is called two times. If we draw the complete tree, 
then we can see that there are many subproblems being called more than once.                                                

//memoization
long long helper(int s[], int m, int n, vector<vector<long long>> &dp){
    if(n == 0)
        return 1;
    if(m == 0)
        return 0;
    if(dp[m][n] != -1)
        return dp[m][n];
    if(s[m-1]<=n)
        return dp[m][n] =  helper(s, m, n-s[m-1], dp) + helper(s, m-1, n, dp);
    else
        return dp[m][n] = helper(s, m-1, n, dp);
}

long long int count(int s[], int m, int n) {
    
    vector<vector<long long>> dp(m+1, vector<long long>(n+1, -1));
    return helper(s, m, n, dp);
}

Time Complexity: O(M*N)
Auxiliary Space: O(M*N)

//tabular
long long int count(int S[], int m, int n) {

    long long dp[m+1][n+1];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0)
                dp[0][j] = 0;
            else if(j == 0)
                dp[i][0] = 1;
            
            else if(S[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i][j-S[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[m][n];
    
}
Time Complexity: O(M*N)
Auxiliary Space: O(M*N)
