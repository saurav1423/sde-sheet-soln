// optimal substructure
// overlapping subproblems

Given two strings str1 and str2 and below operations that can be performed on str1. Find minimum number of edits (operations) required 
to convert ‘str1’ into ‘str2’.  

Insert
Remove
Replace
All of the above operations are of equal cost. 

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a

//brute force
int helper(string word1, string word2, int m, int n){
    
    if(m == 0)
        return n;
    if(n == 0)
        return m;
    
    if(word1[m-1] == word2[n-1])
        return helper(word1, word2, m-1, n-1);
    else
       return 1 + min(helper(word1, word2, m-1, n), min(helper(word1, word2, m, n-1), helper(word1, word2, m-1, n-1)));  
}     
int minDistance(string word1, string word2) {
    
    return  helper(word1, word2, word1.size(), word2.size());
    
}

time - 3^M (M = jis word ko convert krna h uska length)

//why dp
        ED(3, 3)
    /       |       \
ED(3,2)   ED(2,3)  ED(2,2)
 |
ED(3,1) ED(2,1) ED(2,2) 

same problem will start repeating

//tabular
int minDistance(string word1, string word2) {
        
    int m = word1.size();
    int n = word2.size();
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++){
            
            if(i==0)
                dp[0][j] = j;
            else if(j == 0)
                dp[i][0] = i;
            else if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            
        }

    return dp[m][n];

}
time - 0(N*M)
space - 0(N*M)

//space optimized
int minDistance(string word1, string word2) {
        
    int m = word1.size();
    int n = word2.size();
    int dp[2][n+1];
    bool flag;
    
    for(int i=0; i<=m; i++){
        flag = i & 1;
        for(int j=0; j<=n; j++){
            
            if(i==0)
                dp[0][j] = j;
            else if(j == 0)
                dp[flag][0] = i;
            else if(word1[i-1] == word2[j-1])
                dp[flag][j] = dp[1-flag][j-1];
            else
                dp[flag][j] = 1 + min(dp[1-flag][j], min(dp[flag][j-1], dp[1-flag][j-1]));
            
        }
    }
    
    return dp[flag][n];
    
}

time - 0(N*M)
space - 0(N)