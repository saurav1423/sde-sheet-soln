//brute force
for every i, we will iterate whole array and find block having height greater than the current block in both left and right directions.
water store by each block = min(block greater than current block in left, block greater than current block in right) - height of current block

time - 0(N^2)
space - 0(1)

//better
we will make two array, one to store greater in left and one to store greater in right. 

code
 int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> rightMax(n, -1);
        vector<int> leftMax(n, -1);
        
        vector<int> storeWater(n, -1);
        
        int left = -1;
        for(int i=0; i<n; i++){
            leftMax[i] = left;
            left = max(height[i], left);
        }
        
        int right = -1;
        for(int i=n-1; i>=0; i--){
            rightMax[i] = right;
            right = max(height[i], right);
        }
        
        for(int i=0; i<n; i++){
            if(min(leftMax[i], rightMax[i])>height[i])
                storeWater[i] = min(leftMax[i], rightMax[i]) - height[i];
            else
                storeWater[i] = 0;
        }
        
        int sum = 0;
        
        for(int i=0; i<n; i++)
            sum += storeWater[i];
        
        return sum;            
    }

time - 0(N) + 0(N) + 0(N) + 0(N)  overall 0(N)    
space - 0(N) + 0(N) overall 0(N)


//optimal
we will take two pointers, one left and one right. left will point to 0 and right will point to last element. now we will check till left<=right(to cover all block).
now if height[left] < height[right] means, we have in right which is greater than left. so we will check do we have anything in left which is greater than current block height
(lmax>height[left]). if yes then we will add it in answer, if no then we will update our lmax.

int trap(vector<int>& height) {
        
        int n = height.size();
        int left = 0, right = n-1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        
        while(left<=right){
            
            if(height[left] < height[right]){
                if(lmax>height[left])
                    ans += lmax - height[left];
                else
                    lmax = max(lmax, height[left]);
                
                left++;
            }else{
                if(rmax>height[right])
                    ans += rmax - height[right];
                else
                    rmax = max(rmax, height[right]);
                
                right--;
            }
            
        }
        
        return ans;       
}

time - 0(N)
space - 0(1)