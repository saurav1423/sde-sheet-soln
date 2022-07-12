You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

eg - prices = [7,1,5,3,6,4]
Output: 5

int maxProfit(vector<int>& prices) {
        
        int min_so_far = prices[0];
        int max_profit = INT_MIN;
        
        for(int i=0; i<prices.size(); i++){
            
            min_so_far = min(min_so_far, prices[i]);
            int profit = prices[i] - min_so_far;
            max_profit = max(max_profit, profit);
            
        }
        
        return max_profit;
        
    }
};