Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears
only once. The relative order of the elements should be kept the same.

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

//optimal
int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) 
            return 0;
        
        int i = 0;
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;
}

time - 0(N)
space - 0(1)