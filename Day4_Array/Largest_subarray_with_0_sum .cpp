Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

//brute force approach
sara subarray bnaao aur sbka sum check kro, 0 hota to answer me rkho aur bda subarray mile to answer update krdo


//optimal
A[] = {15,-2,2,-8,1,7,10,23}
key is if sum of i=0 is 15 and sum of element at i=0 to i=2 is also 15 means, there is subarray(from i=1 to 2) whose sum is 0

 int maxLen(vector<int>&A, int n)
    {   
        
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++){
            sum += A[i];
            
            if(sum == 0)
               ans = i+1;
            else if(m.find(sum) == m.end())
                m[sum] = i;
            else
                ans = max(ans, i - m[sum]);
        }
        
        return ans;
        
    }
time - 0(N)    
space - 0(N)