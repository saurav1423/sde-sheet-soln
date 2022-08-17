Given an unlimited supply of coins of given denominations, find the minimum number of coins required to get the desired change.
For example, consider S = { 1, 3, 5, 7 }.

If the desired change is 15, the minimum number of coins required is 3
 
(7 + 7 + 1) or (5 + 5 + 5) or (3 + 5 + 7)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
// Function to find the minimum number of coins required
// to get a total of `target` from set `S`
int findMinCoins(vector<int> const &S, int target)
{
    // if the total is 0, no coins are needed
    if (target == 0) {
        return 0;
    }
 
    // return infinity if total becomes negative
    if (target < 0) {
        return INT_MAX;
    }
 
    // initialize the minimum number of coins needed to infinity
    int coins = INT_MAX;
 
    // do for each coin
    for (int i: S)
    {
        // recur to see if total can be reached by including current coin `i`
        int result = findMinCoins(S, target - i);
 
        // update the minimum number of coins needed if choosing the current
        // coin resulted in a solution
        if (result != INT_MAX) {
            coins = min(coins, result + 1);
        }
    }
 
    // return the minimum number of coins needed
    return coins;
}
 
int main()
{
    // coins of given denominations
    vector<int> S = { 1, 2, 3, 4 };
 
    // total change required
    int target = 15;
 
    int coins = findMinCoins(S, target);
    if (coins != INT_MAX)
    {
        cout << "The minimum number of coins required to get the desired change is "
             << coins;
    }
 
    return 0;
}

time - exponential as each recursive call is making n recursive calls.

//optimal
int findMinCoins(vector<int> const &S, int target)
{
    // `T[i]` stores the minimum number of coins needed to get a total of `i`
    int T[target + 1];
    T[0] = 0;        // 0 coins are needed to get a total of `i`
 
    for (int i = 1; i <= target; i++)
    {
        // initialize the minimum number of coins needed to infinity
        T[i] = INT_MAX;
        int result = INT_MAX;
 
        // do for each coin
        for (int c: S)
        {
            // check if the index doesn't become negative by including current coin `c`
            if (i - c >= 0) {
                result = T[i - c];
            }
 
            // if total can be reached by including current coin `c`,
            // update the minimum number of coins needed `T[i]`
            if (result != INT_MAX) {
                T[i] = min(T[i], result + 1);
            }
        }
    }
 
    // `T[target]` stores the minimum number of coins needed to get a total of `target`
    return T[target];
}

time - O(n.target)
space - 0(target)

