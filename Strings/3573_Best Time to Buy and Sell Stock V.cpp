// 3573. Best Time to Buy and Sell Stock V

// TOP DOWN :-
// long long maxProfit(int index, int transc, int buy, vector<int>&prices,vector<vector<vector<long long>>>&dp){

//     if(transc == 0) return 0;

//     if(index == prices.size()){
        
//         if(buy == 1) return INT_MIN;

//         else return 0;
//     }

//     if(dp[index][transc][buy] != -1) return dp[index][transc][buy];
   

//     // not buying , normal buying, short selling :-
//     if(buy == 2){
//         return dp[index][transc][buy] = max(maxProfit(index+1,transc,2,prices,dp), max(-prices[index] + maxProfit(index+1,transc,0,prices,dp),prices[index] + maxProfit(index+1,transc,1,prices,dp)));
//     }

//     // 

//     // short selling, not selling :-
//     else if(buy == 1){
//         return dp[index][transc][buy] = max(-prices[index] + maxProfit(index+1,transc-1,2,prices,dp), maxProfit(index+1,transc,1,prices,dp));
//     }

//         // 
    
//     // normal selling :-
//     else{
//         return dp[index][transc][buy] = max(prices[index]+maxProfit(index+1,transc-1,2,prices,dp), maxProfit(index+1,transc,0,prices,dp));
//     }

//     // 
// }
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int x) {
        
        int n = prices.size();
        if(x == 0) return 0;


        // vector<vector<vector<long long>>>dp(n+1, vector<vector<long long>>(x+1, vector<long long>(3,-1)));
        // return maxProfit(0,x,2,prices,dp);

        // dp[i][j][k] 
        // i -> index : n-1 -> 0
        // j -> transc : 0 -> x
        // k -> buy : 0 -> 2

        // vector<vector<vector<long long>>>dp(n+1, vector<vector<long long>>(x+1, vector<long long>(3,0)));

        vector<vector<long long>>prev(x+1, vector<long long>(3,0));

        for(int i=0; i<=n; i++){
            for(int j=0; j<=x; j++){
                prev[j][1] = INT_MIN;
            }
        }

        for(int i=n-1; i>=0; i--){
            vector<vector<long long>>curr(x+1, vector<long long>(3,0));
            for(int j=1; j<=x; j++){
                for(int k=0; k<=2; k++){

                    if(k == 2){
                        curr[j][k] = max(prev[j][2], max(-prices[i] + prev[j][0], prices[i] + prev[j][1]));
                    }

                    else if(k == 1){
                        curr[j][k] = max(-prices[i] + prev[j-1][2], prev[j][1]);
                    }

                    else{
                        curr[j][k] = max(prices[i] + prev[j-1][2], prev[j][0]);
                    }
                }
            }
            prev = curr;
        }

        return prev[x][2];
            
    }
};
