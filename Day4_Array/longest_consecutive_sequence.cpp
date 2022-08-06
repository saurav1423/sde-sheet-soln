Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

//brute force approach
sort the array and find it

//optimal
take a unordered_set and put every element in it. Then interate over the array and check if num-1 exist or not. Go through code u will get it.

int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        
        for(int i=0; i<nums.size(); i++)
            s.insert(nums[i]);
        
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i]-1) == s.end()){
                int cnt = 0;
                int num = nums[i];
                while(s.find(num) != s.end()){
                    cnt++;
                    num++;
                }
                
            ans = max(ans, cnt);
            }
        }
        
        return ans;
        
    }

time - 0(N)    
space - 0(N)

time - 0(N) how?
see time - 0(N) for pushing in set + 0(N) for interating over array + 0(N) in worst case that while loop take.
eg to understand 
arr = [5, 4, 3, 2, 1]