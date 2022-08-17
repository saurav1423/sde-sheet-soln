S2 - S1 = minimum
S2 can be writtern as arr-S1

so, we have to minimize sum of arr elements - 2S1

as sum of arr elements is fixed, so we have to maximize S1

//code
int minDifference(int arr[], int n){

   int sum = 0;
   for(int i=0; i<n; i++){
    sum += arr[i];
   }
   int newSum = sum/2;

   bool dp[n+1][newSum+1];

   for(int j=0; j<newSum+1; j++)
      dp[0][j] = false;
   for(int i=0; i<n+1; i++)
      dp[i][0] true;

   for(int i=1; i<n+1; i++){
    for(int j=1; j<newSum+1; j++){

      if(arr[i-1]<=j)
         dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
      else
         dp[i][j] = dp[i-1][j];   

     }
   }  

   for(int j=newSum; j>=0; j--){
    if(dp[n][j] == true)
       return sum - 2*j;
   }    

}