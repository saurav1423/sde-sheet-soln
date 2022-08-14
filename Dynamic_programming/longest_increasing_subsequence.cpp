// optimal substructure
// overlapping subproblems

Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}

//brute force
int helper(vector<int> &nums, int ind, int prev){
        
        if(ind == nums.size())
            return 0;
        
        int exec = helper(nums, ind+1, prev);
        
        int inclu = 0;
        if(nums[ind]>prev)
            inclu = 1+ helper(nums, ind+1, nums[ind]);
        
        return max(inclu, exec);
        
        
    }
    
int lengthOfLIS(vector<int>& nums) {
    
    return helper(nums, 0, INT_MIN);
    
}

Time Complexity : O(2^N)
Space Complexity : O(N), max recursive stack depth.

//why to use dp
see, if we have 5, 8, 3, 9, 1
so if we have to find LIS till 9, we have to find till 5, then till 8, then till 3, and then till 9
but if we can store LIS till 3 then LIS at 9 will be 1+prev if 9 is greater than last element. So 
we can store LIS at every number so that we dont have to compute again and again

so dp[i] = max(dp[i], 1+dp[j]) at dp[i], 1 is there, becoz 1 is LIS for that number

int lengthOfLIS(vector<int>& nums) {
    
    int dp[nums.size()];
    
    for(int i=0; i<nums.size(); i++)
        dp[i] = 1;
    
    for(int i=0; i<nums.size(); i++)
        for(int j=0; j<i; j++){
            if(nums[j]<nums[i])
                dp[i] = max(dp[i], 1+dp[j]);
        }
    
    int ans = 1;
    
    for(int i=0; i<nums.size(); i++)
        ans = max(ans, dp[i]);
    
    return ans;
}

time - 0(N^2)
space - 0(N)

//0(NlogN) solution
https://www.youtube.com/watch?v=1qD1FLhKrIE&ab_channel=CodeLibrary-byYogesh%26Shailesh

logic is that we will store the number at index where they make LIS, means lets say 10, now 10 here makes LIS of length 1 only, so we will keep
it at 0 index. Now comming to 5, it also makes LIS of length 1, so we will update 0th index with 5(because getting LIS withh 5 have more chance than
getting it with 10). after doing like this, we will iterate from right and whereever we get number, just return it.

10  5  8  3  9  4  12  11


int lengthOfLIS(vector<int>& nums) {
    
    int n = nums.size();
    int dp[n+1];
    for(int i=1; i<=nums.size(); i++)
        dp[i] = INT_MAX;
    dp[0] = INT_MIN;
    
    for(int i=0; i<nums.size(); i++){
        int idx = upper_bound(dp, dp+n+1, nums[i]) - dp;  //upper_bound dp pe chl rha hai, nums pe ni
        if(nums[i]>dp[idx-1] && nums[i]<dp[idx])
            dp[idx] = nums[i];
    }
    
    int ans = 0;
    for(int i=n; i>=0; i--){
        if(dp[i] != INT_MAX){
            ans = i;
            break;
        }
    }
    
    return ans;
    
}