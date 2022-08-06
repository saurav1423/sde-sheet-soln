Question is very famous so i am not writing it here

//solution 
We will take one max heap and one min heap 
max heap will take care for smaller half numbers and min heap will take care for greater half numbers

If both max and min heap have same size, then coming number will be median 
otherwise after inserting, sum of top of max and min heap element divided by 2 is median 

Now three cases arises 

if(size of max heap>size of min heap)
    if(coming number<median)
       if yes then remove top element of max, insert it in min heap and insert coming element in max heap 
    else
       simply insert it in min heap    

if(size of max = size of min)
   if(coming number<median)
      insert it in max
    else  
      insert it in min

if(size of max heap<size of min heap)
    if(coming number>median)
       remove top element from min heap, insert it in max heap and then insert coming number in min heap
    else   
       insert in max heap

//code

#include<bits/stdc++.h>
using namespace std;

void printMedians(double arr[], int n)
{
    priority_queue<double> s;
    priority_queue<double,vector<double>,greater<double> > g;
  
    double med = arr[0];
    s.push(arr[0]);
  
    cout << med << endl;

    for (int i=1; i < n; i++)
    {
        double x = arr[i];
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
  
            med = (s.top() + g.top())/2.0;
        }
        else if (s.size()==g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (double)s.top();
            }
            else
            {
                g.push(x);
                med = (double)g.top();
            }
        }
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
  
            med = (s.top() + g.top())/2.0;
        }
  
        cout << med << endl;
    }
}
  
int main()
{
    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMedians(arr, n);
    return 0;
}


Time Complexity: O(n Log n). 
Time Complexity to insert element in min heap is log n. So to insert n element is O( n log n).
Auxiliary Space : O(n). 
The Space required to store the elements in Heap is O(n).