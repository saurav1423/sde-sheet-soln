observe carefully, 

we are given, difference between subset, s1-s2 = diff
we know, s1+s2 = sum of array
 adding both, we need to find if there exist a subset with sum = (sum of array + diff)/2

//question boiled to count subset with given sum
however, two important edge case is there
1) multiply the answer(dp[n][s]) with pow(2, cnt), it will consider all subsets of 0 which is not considered earlier
   cnt is count of 0 in array
   return pow(2, cnt) * dp[n][s]

2) if (target+sum)%2 != 0, then return 0 as s1 = target+sum/2   