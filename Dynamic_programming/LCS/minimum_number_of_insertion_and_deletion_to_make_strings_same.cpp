//Minimum number of insertion and deletion to make two string same

eg - str1 = "heap" str2 = "pea"
ans - 3, we have to remove h and p and to insert p to convert str1 to str2

If we look carefully, we have to find LCS of both and then length of(str1+str2) - 2*LCS

int minDistance(string word1, string word2) {
        
    int m = word1.size();
    int n = word2.size();
    
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    
    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            
            else if(word1[i-1] == word2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            
        }
    
    return m+n-2*dp[m][n];
    
}

// seee
minimum number of insertion and deletion, minimum number of insertion, minimum number of deletion aise sbhi question ka solution same hota

replace ghusa dete to pir wo edit distance ho jata aur wha ye logic kaam ni krega