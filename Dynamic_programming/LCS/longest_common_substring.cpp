//Longest Common Substring

Input : X = “GeeksforGeeks”, y = “GeeksQuiz” 
Output : 5 
Explanation:
The longest common substring is “Geeks” and is of length 5.

//recursion

int lcs(int i, int j, int count)
{
 
    if (i == 0 || j == 0)
        return count;
 
    if (X[i - 1] == Y[j - 1]) {
        count = lcs(i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs(i, j - 1, 0),
                    lcs(i - 1, j, 0)));
    return count;
}
 
// Driver code
int main()
{
    int n, m;
 
    X = "abcdxyz";
    Y = "xyzabcd";
 
    n = X.size();
    m = Y.size();
 
    cout << lcs(n, m, 0);
 
    return 0;
}


//dp
int longestCommonSubsequence(string text1, string text2) {
    
    vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, -1));
    
    for(int i=0; i<=text1.size(); i++)
        for(int j=0; j<=text2.size(); j++){
            
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0;
                
            
        }
    //doing this as, it is not compulsory ki answer last box me he hoga

    int res = -1;
    for(int i=0; i<n+1; i++)
      for(int j=0; j<m+1; j++) 
         if(res<dp[i][j])
            res = dp[i][j];

    return res;                
}

time - 0(M*N)
space - 0(M*N)