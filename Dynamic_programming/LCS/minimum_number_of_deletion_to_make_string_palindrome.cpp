// Minimum number of deletion in a string to make it palindrome
//Minimum number of insertion in a string to make it palindrome

eg - AEBCBDA
ans - 2, remove e and d

if we carefully observe, we can see, we have to find LCS between given string and its reverse and then return
length of string minus LCS

n - dp[m][n]