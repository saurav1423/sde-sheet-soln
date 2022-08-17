Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.

//brute force

int rodCut(int price[], int n)
{
    // base case
    if (n == 0) {
        return 0;
    }
 
    int maxValue = INT_MIN;
 
    // one by one, partition the given rod of length `n` into two parts
    // of length (1, n-1), (2, n-2), (3, n-3), … ,(n-1, 1), (n, 0)
    // and take maximum
    for (int i = 1; i <= n; i++)
    {
        // rod of length `i` has a cost `price[i-1]`
        int cost = price[i - 1] + rodCut(price, n - i);
 
        if (cost > maxValue) {
            maxValue = cost;
        }
    }
 
    return maxValue;
}

The time complexity of the above solution is O(nn) and occupies space in the call stack, where n is the rod length.
Now we can use dp to store repeatiness
                   4
            /    |   |    \
           3     2   1     0
        /  |  \    
       2   1   0


//optimal       
int cutRod(int price[], int n) {
    
    // initialize maximum profit to 0
    vector<int> dp(n+1, 0);

    // consider a rod of length `i`
    for(int i=1; i<=n; i++){
        // divide the rod of length `i` into two rods of length `j`
        // and `i-j` each and take maximum
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], price[j-1] + dp[i-j]);
        }
    }
    
    return dp[n];
}

The time complexity of the above bottom-up solution is O(n^2) and requires O(n) extra space, where n is the rod length.