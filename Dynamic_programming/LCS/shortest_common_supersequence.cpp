//shortest common supersequence

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.

//solution
If we look into this carefully, we will observe that we have to return length of x + y - LIS of that strings

int shortestCommonSupersequence(string str1, string str2, int m, int n)
{
    
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    
    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++){
            
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            
        }
    
    return m+n - dp[m][n];
}