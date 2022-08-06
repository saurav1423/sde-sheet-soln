Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.

eg - Input: nums = [2,2,1,1,1,2,2]
     Output: 2

//Brute force approach
pick one number, traverse whole array for it, check if it occur more than n/2, if yes then return
time - 0(N^2)

//better
use unordered_map and store count of element. if count >n/2 return it as answer
time - 0(N) space - 0(N)

//optimal
 int majorityElement(vector<int>& nums) {
        
        int ans = 0;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            if(count == 0){
                ans = nums[i];
                count = 1;
            }else{
                if(nums[i] == ans)
                    count++;
                else
                    count--;
            }
                
                
        }
        
        
        return ans;
    }
time - 0(N) space - 0(1)    