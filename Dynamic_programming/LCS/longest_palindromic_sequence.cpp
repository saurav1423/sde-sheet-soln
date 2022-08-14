//longest palindromic sequence

eg - GEEKSFORGEEKS
ans - 5 (EEKEE or EESEE ...)

if you observe we can get the answer by finding LCS between given string and it reverse

int longestPalindromeSubseq(string s) {
        
    string y = "";
    
    for(int i=s.size()-1; i>=0; i--)
        y+=s[i];
    
    int m = s.size();
    int n = y.size();
    
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    
    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            
            else if(s[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            
        }
    
    return dp[m][n];
    
}