Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]

//brute force approach
do for loop chalake, i, j pe jo nums ho uska sum target h ya ni, hai to return.
time - 0(N*2)  space - 0(1)

//optimal
use unordered map

interate on array, if target - num is not in map, then push num.
vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int, int> m;
        
        for(int i=0; i<nums.size(); i++){
            if(m.find(target-nums[i]) == m.end()){
                m[nums[i]] = i;
            }else{
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
            }
        }
        
        return ans;
        
    }
time - 0(N) space - 0(N)    
