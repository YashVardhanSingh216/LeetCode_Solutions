// 122. Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int prevprofit = prices[0];
        int profit = 0;

        for(int i=1; i<n; i++){

            if(prices[i] > prevprofit){
                profit += prices[i] - prevprofit;
                prevprofit = prices[i];
            }
            else{
                prevprofit = prices[i];
            }
        }

        return profit;
    }
};
