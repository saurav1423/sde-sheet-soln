//brute
sorting se ho jayega
time - 0(NlogN)

//better
use unordered map to store count, jiska 2 count hai wo repeat kiya
time - 0(N)  space - 0(N)

//better
int findDuplicate(vector<int>& nums) {
        
        int ans = -1;
        
        for(int i=0; i<nums.size(); i++)
            if(nums[abs(nums[i])] > 0)
                nums[abs(nums[i])] = -nums[abs(nums[i])];
             else{
                 ans = abs(nums[i]);
                 break;
             }
        
        return ans;
        
    }
time - 0(N)  space - 0(1)

//optimal
int findDuplicate(vector<int>& nums){
    int slow = num[0];
    int fast = num[0];

    do{
        slow = num[slow];
        fast = num[num[fast]];
    }while(slow != fast);

    fast = num[0];
    while(slow != fast){
        slow = num[slow];
        fast = num[fast];
    }

    return slow;
}
time - 0(N) space - 0(1)

//why they will meet (proof)

|----L1-------||--L2-|
1 -- 2 -- 3 -- 4 -- 5
              |     |
               7 -- 6

let say slow and fast meet at 5 when slow was moving 1 step and fast was moving 2 steps.
let say length from 1 to 4 is L1 and 4 to 5 is L2 and 5 to 4 is L3

fast = num[0];
while(slow != fast){
  slow = num[slow];
  fast = num[fast];
}

now according to above code and the lines we wrote 
fast will move L1 and slow will move L3
So if we can proof that L1 and L3 is equal then both will meet at 4 for sure, will get proved 

proof:-
before meeting 
slow moved = L1 + L2
fast moved = L1 + L2 + nC [where n is integer and c is length of loop]  -- 1

also we know fast distance = 2*slow distance
putting in 1
2(L1 + L2) = L1 + L2 + nC
L1+L2 = nC
L1 = nC - L2
   = L3

(Try to thing vro, you will get it)   