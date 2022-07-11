Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

// Brute force solution will be to sort the array
time - 0(nlogn),  space - 0(1)


// 2nd solution
Use counting sort(for loop chalao, 0,1,2 ke occurances ko count krlo)
pirse for loop chalake jitne 0 thai, utna 0 daal do array me, jitne 1 thai utne 1 and so on
time - 0(N) + 0(N)   space - 0(1)


//optimal solution
void sortColors(vector<int>& nums) {
       int lo = 0; 
        int hi = nums.size() - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
    }

 time - 0(N)  space - 0(1)   