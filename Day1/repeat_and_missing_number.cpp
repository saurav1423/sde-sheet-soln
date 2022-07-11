//brute force 
number 0 se n me hoga diya hai. so we can make an array of size n+1 where we will store the count of each element
and then we will see which one count is missing, and which one have 2 as a count.
time - 0(N) + 0(N)  space - 0(N)

//better 
1+2+3+4...n = n(n+1)/2 = S 
s - given number sum = X - Y (X being missing and Y is repeating)
same we can find 1^2 + 2^2 + 3^2 + 4^2 ... = s^2
s^2 - given number sum square = X^2 - Y^2 
now we have X^2 - Y^2 and X - Y, we can find both missing and repeating

//optimal
int *findTwoElement(int *arr, int n) {
        
        int *ans = new int(2);
        int repeat = arr[0];
        int missing = arr[0];
        
        for(int i=0; i<n; i++){
            if(arr[abs(arr[i])-1] > 0){
                arr[abs(arr[i])-1] = - arr[abs(arr[i])-1];
            }else{
                repeat = abs(arr[i]);
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i]>0){
                missing = i+1;
            }
        }
        
        ans[0] = repeat;
        ans[1] = missing;
        
        return ans;
        
     }

time - 0(N) space - 0(1)