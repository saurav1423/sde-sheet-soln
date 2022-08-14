// optimal substructure
// overlapping subproblems

//Longest common Subsequence

LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4. 

//brute force
int LCSLength(string X, string Y, int m, int n)
{
    // return if the end of either sequence is reached
    if (m == 0 || n == 0) {
        return 0;
    }
 
    // if the last character of `X` and `Y` matches
    if (X[m - 1] == Y[n - 1]) {
        return LCSLength(X, Y, m - 1, n - 1) + 1;
    }
 
    // otherwise, if the last character of `X` and `Y` don't match
    return max(LCSLength(X, Y, m, n - 1), LCSLength(X, Y, m - 1, n));
}
 
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
 
    cout << "The length of the LCS is " <<
            LCSLength(X, Y, X.length(), Y.length());
 
    return 0;
}

 time - O(2^(m+n)) 

// now as we can see 

                      lcs("AXYT", "AYZX")
                       /                \ 
         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
         /                              /               
lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")

lcs(“AXY”, “AYZ”) is solved twice, which can be avoided if we can store the result.

//memoized
int LCSLength(string X, string Y, int m, int n, vector<vector<int>> &dp)
{
    // return if the end of either sequence is reached
    if (m == 0 || n == 0) {
        return 0;
    }
    
    if(dp[m][n] != -1)
       return dp[m][n];
 
    // if the last character of `X` and `Y` matches
    if (X[m - 1] == Y[n - 1]) {
        return dp[m][n] =  LCSLength(X, Y, m - 1, n - 1, dp) + 1;
    }
 
    // otherwise, if the last character of `X` and `Y` don't match
    return dp[m][n] = max(LCSLength(X, Y, m, n - 1, dp), LCSLength(X, Y, m - 1, n, dp));
}

time - 0(N^2)
space - 0(N^2)

//tabular
int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, -1));
        
        for(int i=0; i<=text1.size(); i++)
            for(int j=0; j<=text2.size(); j++){
                
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                 
                
            }
        
        return dp[text1.size()][text2.size()];
        
    }

time - 0(M*N)
space - 0(M*N)

//space optimized
As we can see, we need only previous row to fill current row, so we can solve it by taking two rows only

result of & of two number is 1 if both are 1

int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(2, vector<int> (text2.size()+1, -1));
        bool bi;
        
        for(int i=0; i<=text1.size(); i++){
            bi = i & 1;
            for(int j=0; j<=text2.size(); j++){
                
                if(i == 0 || j == 0)
                    dp[bi][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    dp[bi][j] = 1 + dp[1-bi][j-1];
                else dp[bi][j] = max(dp[1-bi][j], dp[bi][j-1]);
                 
                
            }
        }
        
        return dp[bi][text2.size()];
        
    }

Time Complexity : O(m*n) 
Auxiliary Space : O(n)    

