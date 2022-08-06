The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Input: n = 3, k = 3
Output: "213"

//brute force
brute force will be to generate all the permutations on the given number and then return kth permutation sequence

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    //function to generate all possible permutations of a string
    void solve(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        solve(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    solve(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }
};

int main() {
  int n = 3, k = 3;
  Solution obj;
  string ans = obj.getPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}

Time complexity: O(N! * N) +O(N! Log N!)

Reason:  The recursion takes O(N!)  time because we generate every possible permutation and another O(N)  time is required to make a deep copy and store every sequence in the data structure. Also, O(N! Log N!)  time required to sort the data structure

Space complexity: O(N) 

Reason: Result stored in a vector, we are auxiliary space taken by recursion

//optimal
Since this is a permutation we can assume that there are four positions that need to be filled using the four numbers of the sequence.
First, we need to decide which number is to be placed at the first index. Once the number at the first index is decided we have three more
positions and three more numbers.  Now the problem is shorter. We can repeat the technique that was used previously until all the positions
are filled. The technique is explained below.

Now think like this, if we have number 1,2,3,4, permutation starting with number 1 will be factorial of 3 i.e. 6. Means 6 numbers can be formed
which can start with 1. Same thing apply for 2, 3 and 4. Now let say we fixed 1. So number starting with 2 will be factorial of 2 i.e. 2.
We can use this logic to find kth permutation.

Let say we have 1, 2, 3, 4. Total numbers starting with 1 will be 6(0-5 index). Total number starting with 2 will be 6(6-11) and so on  
Means if we are given k from 1 to 6, the first number will be 1. we can 
use this logic to solve this question. Lets go through code, it will be easy


#include <bits/stdc++.h>

using namespace std;

k/fact tells which block(like kis number se chaalu hoga)
k%fact tells knsa sequence hoga uss number ka

class Solution {
  public:
    string getPermutation(int n, int k) {
      int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size(); //to reduce the factorial (jese 3! tha, but ab pehla place fix ho gy to ab 2! he bache remaining position ke liye)
      }
      return ans;
    }
};

int main() {
  int n = 3, k = 3;
  Solution obj;
  string ans = obj.getPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}

Time Complexity: O(N) * O(N) = O(N^2)

Reason: We are placing N numbers in N positions. This will take O(N) time. For every number, we are reducing the search space by removing the element already placed in the previous step. This takes another O(N) time.

Space Complexity: O(N) 

Reason: We are storing  the numbers in a data structure(here vector)

