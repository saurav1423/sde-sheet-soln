Given an integer array nums and an integer k, return the kth smallesr element in the array.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

//brute force
sort the array and return kth element
time - 0(NlogN)

//better
Using Max Heap

Idea is to first insert k elements, then if element is smaller than top element, remove top element and insert that element. This way we will be
having kth smallest at top of our array


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int findKthSmallest(vector<int> const &ints, int k)
{
    if (ints.size() < k) {
        exit(-1);
    }
 
    priority_queue<int, vector<int>> pq(ints.begin(), ints.begin() + k);
 
    for (int i = k; i < ints.size(); i++)
    {
        if (ints[i] < pq.top())
        {
            pq.pop();
            pq.push(ints[i]);
        }
    }
    return pq.top();
}
 
int main()
{
    vector<int> ints = { 7, 4, 6, 3, 9, 1 };
    int k = 2;
    cout << "k'th largest array element is " << findKthLargest(ints, k);
    return 0;
}

time - 0(nlogk) as priority queue will have k element at every time, so inserting any element will take 0(logk) and we are inserting n elements
so 0(nlogk)


//Using Min Heap

int findKthSmallest(vector<int> &ints, int k)
{
    if (ints.size() < k) {
        exit(-1);
    }
    priority_queue<int, vector<int>, greater<int> >pq;
    for(int i=0; i<ints.size(); i++)
       pq.push(ints[i]);

    while (--k) {
        pq.pop();
    }
    return pq.top();
}

time - n + klog(n) , n time to push all elements in max heap. then klogn as we are popping k times and to pop it takes logn time(as it have n elements
and rearranging take logn times everytime).


//using quickselect
First we will be selecting any random element as PIVOT 
then we will try to partition array in two half which is, all elements smaller than pivot will be on left and larger than pivot will be in right.
Now since, all elements right to the PIVOT are greater and left to the PIVOT are smaller ,we will compare index with N-k ( where N = size of array )
and recursively find the part to find the Kth largest element.


#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int l, int r)
{
	int f = arr[r] ;
	int i = l;

	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= f) {
			swap(arr[i], arr[j]) ;
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}


int kth_Smallest_Element(vector<int>&arr, int l, int r, int k)
{
	if (k <= r - l + 1 && k > 0) {

		int ind = partition(arr, l, r);


		if (ind - l == k - 1) {
			return arr[ind];
		}
		if (ind - l > k - 1) {
			return kth_Smallest_Element(arr, l, ind - 1, k);
		}


		return kth_Smallest_Element(arr, ind + 1, r, k - ind + l - 1);
	}
	return INT_MAX;
}

int main()
{

	vector<int>arr ;
	arr.push_back(12) ;
	arr.push_back(3)  ;
	arr.push_back(5) ;
	arr.push_back(7)  ;
	arr.push_back(4) ;
	arr.push_back(19)  ;
	arr.push_back(26) ;

	int n = arr.size(), k = 1;
	cout << "Kth smallest element is " << kth_Smallest_Element(arr, 0, n - 1, k);
	return 0;
}
 
time - 0(N)
space - 0(1)