Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.

//brute force
generate all subarray and find maximum product from them

// C++ program to find Maximum Product Subarray
#include <bits/stdc++.h>
using namespace std;

/* Returns the product of max product subarray.*/
int maxSubarrayProduct(int arr[], int n)
{
	// Initializing result
	int result = arr[0];

	for (int i = 0; i < n; i++)
	{
		int mul = arr[i];
		// traversing in current subarray
		for (int j = i + 1; j < n; j++)
		{
			// updating result every time
			// to keep an eye over the maximum product
			result = max(result, mul);
			mul *= arr[j];
		}
		// updating the result for (n-1)th index.
		result = max(result, mul);
	}
	return result;
}

// Driver code
int main()
{
	int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum Sub array product is "
		<< maxSubarrayProduct(arr, n);
	return 0;
}

//optimal
long long maxProduct(vector<int> arr, int n) {
	    
        long long maxval = arr[0];
        long long minval = arr[0];
        long long prod = arr[0];
        
        for(int i=1; i<n; i++){
            
            if(arr[i]<0){
                swap(maxval, minval);
            }
            if(arr[i]>maxval*arr[i]){
                maxval = arr[i];
            }else{
                maxval *= arr[i];
            }
            if(arr[i]<minval*arr[i]){
                minval = arr[i];
            }else{
                minval *= arr[i];
            }
            
            prod = max(prod, maxval);
            
            
        }
        
        return prod;
}
