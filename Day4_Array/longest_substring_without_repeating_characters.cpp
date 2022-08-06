Given a string s, find the length of the longest substring without repeating characters.
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

//brute force approach
sara substring generate kro aur check krlo kisme repeating characters ni hai{use set to store element, so that you can check whether number previously existed or not}

to erase whole unordered_set

unordered_set<int> sampleSet;
sampleSet.erase(sampleSet.begin(), sampleSet.end());

//better
ek left = 0, right = 0, aur ek unordered_set lenge, arr[right] agar unordered_set me ni hai to push krenge aur ans{ = right-left+1}. jb arr[right] unordered_set me hoga to pir arr[left] ko
unordered_set se erase kr denge, aur left++ krenge. pirse check krenge ki arr[right] exist krta hai ya ni, agar ha, to pir se arr[left] erase krenge aur left++ krenge.

time - 0(2N), one character will be visited twice at max, one by right and one by left
eg = abcdzz, consider right at last z and left at a


//optimal
instead of moving our left variable one step at a time, we can use unordered_map to store the index of every element as well, and whenever we encounter any repeating characters
we will use index to directly jump one step ahead.

int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> umap;
        int left=0, right=0;
        int len = 0;
        
        while(right<s.size()){
            
            if(umap.find(s[right]) != umap.end())
                low = max(low, umap[s[right]]+1);
            
            umap[s[right]] = right;
            
            len = max(len, right-low+1);
            right++;
            
            
        }
        
        return len;
        
    }

time - 0(N)    
space - 0(N)