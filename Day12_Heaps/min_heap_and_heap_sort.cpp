#include<iostream>
using namespace std;

//Min Heap(for 0 based indexing)
//for 1 based indexing, left = 2*i and right = 2*i + 1

void heapify(vector<int> &arr, int n, int i){

   int smallest = i;
   int left = 2*i + 1;
   int right = 2*i + 2;

   if(left<n && arr[smallest] > arr[left])
      smallest = left;

   if(right<n && arr[smallest] > arr[right])
      smallest = right;  

   if(smallest != i){
      swap(arr[smallest], arr[i]);
      heapify(arr, n, smallest);
   }
}   

vector<int> buildMinHeap(vector<int> &arr){

   int n = arr.size();
   for(int i = n/2-1; i >= 0; i--)
       heapify(arr, n, i);
    
    return arr;
}   


//Max heap ke liye bhut small changes (0  based indexing)


void heapify(vector<int> &arr, int n, int i){

   int largest = i;
   int left = 2*i + 1;
   int right = 2*i + 2;

   if(left<n && arr[largest] < arr[left])
      smallest = left;

   if(right<n && arr[largest] < arr[right])
      largest = right;  

   if(largest != i){
      swap(arr[largest], arr[i]);
      heapify(arr, n, largest);
   }
}   


//Max heap ke liye bhut small changes (1  based indexing)


void heapify(vector<int> &arr, int n, int i){

   int largest = i;
   int left = 2*i;
   int right = 2*i + 1;

   if(left<=n && arr[largest] < arr[left])
      smallest = left;

   if(right<=n && arr[largest] < arr[right])
      largest = right;  

   if(largest != i){
      swap(arr[largest], arr[i]);
      heapify(arr, n, largest);
   }
}   



//HeapSort
sort krna hai heap(max or min) ko

1) swap root value by last element(size)
2) rearrange the tree and push the root value to its correct place
3) size--
4) again repeat step 1,2,3


void heapSort(int arr[], int n){

    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }

}

time complexity for heapsort = 0(NlogN)



//To use max heap and min heap, we can use priority queue
#include<queue>

priority_queue<int> pq;   //ye max heap hota hai
priority_queue<int, vector<int>, greater<int>> pq;   //ye min heap hota hai
