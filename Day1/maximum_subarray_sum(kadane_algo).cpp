Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number)
which has the maximum sum and return its sum.

eg -
Arr[] = {1,2,3,-2,5}
ans - 9  (from 1, 2, 3, -2, 5)

//brute force approach
we will travarse over all subarray and will count maximum subarray sum and then return it 
for making subarray 
for(int i = 0 to n-1){
    for(int j = i to n-1 ){
        for(int k = i to j){
            sum += arr[k];
        }
        maxi = max(maxi, sum);
    }
}

time - 0(n^3) space - o(1)

//optimal
 int maxSubArray(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int sum = 0;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            
            sum += nums[i];
            
            maxi = max(maxi, sum);
            
            if(sum<0){
                sum = 0;
            }
        }
        
        
        return maxi;
    }

 time - 0(N)  space - 0(1)