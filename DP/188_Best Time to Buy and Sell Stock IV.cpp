// 188. Best Time to Buy and Sell Stock IV

//  TOP DOWN:-
// int maximumProfit(int index,int buy,int k,vector<int>&prices,vector<vector<vector<int>>>&dp){
//     // k -> transaction
//     if(k == 0 || index == prices.size()) return 0;
//     if(dp[index][buy][k] != -1) return dp[index][buy][k];

//     if(buy == 1){
//         dp[index][buy][k] = max(-prices[index]+maximumProfit(index+1,0,k,prices,dp),maximumProfit(index+1,1,k,prices,dp));
//     }

//     else{
//         dp[index][buy][k] = max(prices[index] + maximumProfit(index+1,1,k-1,prices,dp),maximumProfit(index+1,0,k,prices,dp));
//     }

//     return dp[index][buy][k];
// }
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return maximumProfit(0,1,k,prices,dp);

        //  BOTTOM UP:-
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // i -> index : n -> 0
        // j -> buy : 1 -> 0
        // l -> k/trnsaction : k -> 0
        // for(int i=n-1; i>=0; i--){
        //     for(int j=0; j<=1; j++){
        //         for(int l=1; l<=k; l++){
                    
        //             if(j == 1)
        //             dp[i][j][l] = max(-prices[i] + dp[i+1][0][l], dp[i+1][1][l]);

        //             else
        //             dp[i][j][l] = max(prices[i] + dp[i+1][1][l-1], dp[i+1][0][l]);
                    
        //         }
        //     }
        // }

        // return dp[0][1][k];


        // SPACE OPTIMIZATION :-
        vector<vector<int>>prev(2, vector<int>(k+1,0));

        for(int i=n-1; i>=0; i--){
        vector<vector<int>>curr(2, vector<int>(k+1,0));
            for(int j=0; j<=1; j++){
                for(int l=1; l<=k; l++){
                    
                    if(j == 1)
                    curr[j][l] = max(-prices[i] + prev[0][l], prev[1][l]);

                    else
                    curr[j][l] = max(prices[i] + prev[1][l-1], prev[0][l]);
                    
                }
            }

            prev = curr;
        }

        return prev[1][k];
    }
};
