Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

// brute  force
will check for all the triplets by running three for loop.we will use unordered_set to keep triplets(push in sorted order)to get unique set only
time - 0(N^3)
space - 0(M) , M being number of triplets in our answer


//better
will run two for loop for a and b and will check for c(which is -(a+b)) in unordered map.
first we will make an unordered map and store all element with there count.
Now we will run two for loop, one for a and other for b. We will decrease count in unordered map for a and b and then search for c(-(a+b)) in unordered map.
If we get it, we will store it in unordered set in sorted order (for unique triplets).

for(int i=0; i<n; i++){
    umap[vec[i]]--;
    for(int j=i+1; j<n; j++){
        umap[vec[j]]--;
        if(umap.find(-(vec[j]+vec[i])) != umap.end()){
            then store it after sorting
        }
        umap[vec[j]]++;
    }
    umap[vec[i]]++;
}

time - 0(N^2)
space - 0(M) [for set] + 0(N) [for map]

//return in any order khe to unordered set lena ni to sirf set(time complexity logm se bd jayega)

//optimal (we will use two pointer approach)
vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) 
            return 0;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            
            if(i == 0 || (i>0 && nums[i] != nums[i-1])){
                int n1 = nums[i];
            int low = i+1;
            int high = nums.size()-1;
            
            while(low<high){
                if(nums[low] + nums[high] == -n1){
                    vector<int> no = {n1, nums[low], nums[high]};
                    ans.push_back(no);
                    while(low<high && nums[low+1] == nums[low])low++;
                    while(low<high && nums[high-1] == nums[high])high--;
                    low++;
                    high--;
                }
                else if(nums[low] + nums[high] < -n1)
                    low++;
                else
                    high--;
            }
        
            }    
        }
        
        return ans;
        
    }

in both while loop, we are writing low<high so that they not get out of bound [try on eg = 0,0,0]

time - 0(NlogN)
space - 0(M)