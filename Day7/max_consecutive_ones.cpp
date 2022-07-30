Given a binary array nums, return the maximum number of consecutive 1's in the array.
Input: nums = [1,1,0,1,1,1]
Output: 3

Maybe warmup problem, so directly jump to optimal solution

int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int cnt = 0; 
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1)
                cnt++;
            else
                cnt = 0;
            ans = max(ans, cnt);
        }
        
        return ans;
        
}


time - 0(N)
space - 0(1)