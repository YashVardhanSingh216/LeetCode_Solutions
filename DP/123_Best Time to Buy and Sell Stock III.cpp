// 123. Best Time to Buy and Sell Stock III

// METHOD 1 :-

int maximumprofit(int index,int buy,int transc,vector<int>&prices,vector<vector<vector<int>>>&dp){

    if(transc == 0 || index == prices.size()) return 0;
    int result = 0;
 
    if(dp[index][buy][transc] != -1) return dp[index][buy][transc];
    // buy karna h
    if(buy == 1){
                // buy kar liya                                              // buy nhi kiya
        result+= max(-prices[index] + maximumprofit(index+1,0,transc,prices,dp),maximumprofit(index+1,1,transc,prices,dp));

    }
    else{
                // sell kar liya                                             // sell nhi kiya  
        result+= max(prices[index] + maximumprofit(index+1,1,transc-1,prices,dp), maximumprofit(index+1,0,transc,prices,dp));
    }

    return dp[index][buy][transc] = result;
}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // return maximumprofit(0,1,2,prices,dp);

        // index : i : n -> 0
        // buy : j : 0 -> 1
        // transc : k : 0 -> 2

        // for(int i=n-1; i>=0; i--){
        //     for(int j=0; j<=1; j++){
        //         for(int k=1; k<=2; k++){

        //             if(j == 1){
        //                 dp[i][j][k] = max(-prices[i] + dp[i+1][0][k], dp[i+1][1][k]);
        //             }
        //             else{
        //                 dp[i][j][k] = max(prices[i] + dp[i+1][1][k-1], dp[i+1][0][k]);
        //             }
        //         }
        //     }
        // }


        vector<vector<int>>prev(2, vector<int>(3,0));
        // i -> curr
        // i+1 -> prev (because the loop is inverse)

        for(int i=n-1; i>=0; i--){
        vector<vector<int>>curr(2, vector<int>(3,0));
            for(int j=0; j<=1; j++){
                for(int k=1; k<=2; k++){

                    if(j == 1){
                        curr[j][k] = max(-prices[i] + prev[0][k], prev[1][k]);
                    }
                    else{
                        curr[j][k] = max(prices[i] + prev[1][k-1], prev[0][k]);
                    }
                }
            }

            prev = curr;
        }

        return prev[1][2];
    }
};







// METHOD 2 :-

int maximumProfit(int n,int transc,vector<int>&prices,vector<vector<int>>&dp){

    if(transc == 0 || n<=1) return 0;

    if(dp[transc][n] != -1) return dp[transc][n];

    // sell nhi kiya
    int targetProfit =  maximumProfit(n-1,transc,prices,dp);

    for(int j=n-1; j>=1; j--){
        targetProfit = max(targetProfit, prices[n-1] - prices[j-1] + maximumProfit(j,transc-1,prices,dp));
    }

    return dp[transc][n] = targetProfit;
}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        vector<vector<int>>dp(3,vector<int>(n+1,-1));
        return maximumProfit(n,2,prices,dp);
    }
};
