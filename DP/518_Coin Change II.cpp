// 518. Coin Change II

int FindWays(int n,vector<int>&coins,int amount,vector<vector<int>>&dp){
    if(amount == 0) return 1;
    if(n == 0 || amount < 0) return 0;
    if(dp[n][amount] != -1) return dp[n][amount];

    return dp[n][amount] = FindWays(n-1,coins,amount,dp) + FindWays(n,coins,amount - coins[n-1],dp);

    // dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
}
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        // Recurssive :
        // return FindWays(n,coins,amount);

        // Top Down
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return FindWays(n,coins,amount,dp);

        // Bottom Up
        // vector<vector<int>>dp(n+1,vector<int>(amount+1,0));

        // for(int j=0; j<=n; j++){
        //     dp[j][0] = 1;
        // }

        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<= amount; j++){

        //         if(j - coins[i-1] >= 0)
        //         dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];

        //         else dp[i][j] = dp[i-1][j];
        //     }
        // }

        // return dp[n][amount];

        // SPACE OPTIMIZATION:
        // vector<int>curr(amount+1,0);

        // curr[0]  = 1;
    
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<= amount; j++){

        //         if(j - coins[i-1] >= 0)
        //         curr[j] = curr[j] + curr[j - coins[i-1]];

        //         // else curr[j] = prev[j];
        //     }
        //     // prev = curr;
        // }

        // return curr[amount];
    }
};
