There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time.
Count the number of ways, the person can reach the top.


//brute force(recursion)
We can observe, a person can reach nth stair only from n-1th stair and n-2th stair.
so we will find ways to reach n-1th and n-2th stairs and add them to get the answer

ways(n) = ways(n-1) + ways(n-2)

The above expression is fibonacci series but one thing to note is that value of ways(n) = fib(n+1)

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
 
// Returns number of ways to
// reach s'th stair
int countWays(int s)
{
    return fib(s + 1);
}

time - 2^n

                  fib(5)
           '3'  /        \   '2'
               /          \
           fib(4)         fib(3)
     '2'  /      \ '1'   /      \  
         /        \     /        \ 
     fib(3)     fib(2)fib(2)      fib(1) 
     /    \ '1' /   \ '0'
'1' /   '1'\   /     \ 
   /        \ fib(1) fib(0) 
fib(2)     fib(1)


//Memoization
int fib(int n, int dp[])
{
    if (n <= 1)
        return dp[n] = 1;
 
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}
 
// Returns number of ways to reach s'th stair
int countWays(int n)
{
    int dp[n + 1];
    memset(dp, -1, sizeof dp);
    fib(n, dp);
    return dp[n];
}

Time Complexity: O(n)
Auxiliary Space: O(n)

