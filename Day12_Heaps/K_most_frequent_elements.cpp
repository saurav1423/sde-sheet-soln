Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. If two numbers have the same 
frequency then the larger number should be given preference. 

Note: Print the elements according to the frequency count (from highest to lowest) and if the frequency is equal then larger number will be
given preference.

Input:
N = 6
nums = {1,1,1,2,2,3}
k = 2
Output: {1, 2}

//Brtue
Algorithm: 
Create a Hashmap hm, to store key-value pair, i.e. element-frequency pair.
Traverse the array from start to end.
For every element in the array update hm[array[i]]++
Store the element-frequency pair in a vector and sort the vector in decreasing order of frequency.
Print the first k elements of sorted array.

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    // if frequencies of two elements are same
    // then the larger number should come first
    if (p1.second == p2.second)
        return p1.first > p2.first;
 
    // sort on the basis of decreasing order
    // of frequencies
    return p1.second > p2.second;
}

// store the elements of 'um' in the vector 'freq_arr'
vector<pair<int, int> > freq_arr(um.begin(), um.end());

// sort the vector 'freq_arr' on the basis of the
// 'compare' function
sort(freq_arr.begin(), freq_arr.end(), compare);


Time Complexity: O(d log d), where d is the count of distinct elements in the array. To sort the array O(d log d) time is needed.
Auxiliary Space: O(d), where d is the count of distinct elements in the array. To store the elements in HashMap O(d) space complexity is needed.


//OPTIMAL AND WORK ONLY IF NUMBER IN ARRAY IS GREATER THAN 0 

first store count of occurrences in unordered map, then use vector to store on basis of count and then print

#include <bits/stdc++.h>
using namespace std;
void print_N_mostFrequentNumber(int arr[], int n, int k)
{
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
        um[arr[i]]++;

    vector<int> freq[n + 1]; (as maximum count of number can be n+1)
    for (int i = 0; i < n; i++) {
        int f = um[arr[i]];
        if (f != -1) {
            freq[f].push_back(arr[i]);
            um[arr[i]] = -1;
        }
    }
    int count = 0;
    for (int i = n; i >= 0; i--) {
        for (int x : freq[i]) {
            cout << x << " ";
            count++;
            if (count == k)
                return;
        }
    }
}
 
int main()
{
    int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    print_N_mostFrequentNumber(arr, n, k);
    return 0;
}

time - 0(N)
space - 0(N)


//optimal(use unordered map and priority queue(MIN HEAP))
cant be solved using max heap 

vector<int> topKFrequent(vector<int>& nums, int k) {
        
         unordered_map<int,int> mp;
        for(auto a : nums)
        {
            mp[a]++;   //map will have value (no, freq)
        }
        
        //create a min heap in which each value will be a pair of form (freq, no)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto i = mp.begin(); i != mp.end(); i++)
        {
            pq.push({i->second, i->first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while(pq.size() > 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
} 

time - 0(NlogK)
space - 0(N)