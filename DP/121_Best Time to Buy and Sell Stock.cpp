// 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int prevprofit = prices[0];
        int profit = 0;

        for(int i=1; i<n; i++){
            if(prices[i] > prevprofit){
                profit = max(profit, prices[i] - prevprofit);
            }
            else{
                prevprofit = prices[i];
            }
        }

        return profit;
    }
};
