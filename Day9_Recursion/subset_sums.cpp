Given a list arr of N integers, print sums of all subsets in it.

Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.

//optimal
class solution
{
    public:
    void helper(int sum, int i, int n, vector<int> &ans, vector<int> &arr){
        
        if(i == n){
            ans.push_back(sum);
            return;
        }
        
        helper(sum+arr[i], i+1, n, ans, arr);
        helper(sum, i+1, n, ans, arr);
        
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        helper(0, 0, N, ans, arr);
        return ans;
    }
}

ans sort krke return kiya to O(2^n log(2^n)) itna time jud jayega means time is O(2^n)+O(2^n log(2^n))

otherwise
time - O(2^n)