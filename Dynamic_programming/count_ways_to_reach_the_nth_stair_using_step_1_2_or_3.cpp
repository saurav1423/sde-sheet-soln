A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up the stairs.

//recursion
To reach a stair i, a person has to jump either from i-1, i-2 or i-3 th stair or i is the starting stair.

 int findStep(int n)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;

    else
        return findStep(n - 3) + findStep(n - 2)
                + findStep(n - 1);
}


Time Complexity: O(3n)

//memoization
 int findStepHelper(int n, vector<int>& dp)
{
    // Base Case
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;
    // If subproblems are already calculated
    //then return it
    if (dp[n] != -1) {
        return dp[n];
    }

    // store the subproblems in the vector
    return dp[n] = findStepHelper(n - 3, dp)
                    + findStepHelper(n - 2, dp)
                    + findStepHelper(n - 1, dp);
}

Time Complexity: O(n)
Space Complexity: O(n)