// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// TOP dOWN:-
int FindMaxVal(int n, int W, vector<int>&wt, vector<int>&val, vector<vector<int>>&dp){
    
    if(W < 0) return INT_MIN;
    
    if(n == 0 || W == 0) return 0;
    
    if(dp[n][W] != -1) return dp[n][W];
    
    
    
    return  dp[n][W] = max(FindMaxVal(n-1,W,wt,val,dp), val[n-1] +  FindMaxVal(n-1,W - wt[n-1],wt,val,dp));

    // i -> n
    // j -> W
    // dp[i][j] = max(dp[i-1][j], val[i-1][j - wt[i-1]])
    
}
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
    
        int n = wt.size();
        // vector<vector<int>>dp(n+1,vector<int>(W + 1, -1));
        // return FindMaxVal(n,W,wt,val,dp);
        
        // BOTTOM UP:-
        // vector<vector<int>>dp(n+1,vector<int>(W + 1, 0));
        
        // for(int i=1; i<=n ;i++){
        //     for(int j=1; j<= W; j++){
                
        //         if(j - wt[i-1] >= 0)
        //         dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
                
        //         else
        //         dp[i][j] = dp[i-1][j];
        //     }
        // }
        
        // return dp[n][W];

      // SPACE OPTIMIZATION :-
        vector<int>prev(W+1,0);
        
        for(int i=1; i<=n; i++){
            vector<int>curr(W+1,0);
            
            for(int j=1; j<=W; j++){
                
                if(j - wt[i-1] >= 0)
                curr[j] = max(prev[j], val[i-1] + prev[j - wt[i-1]]);
                
                else
                curr[j] = prev[j];
            }
            
            prev = curr;
        }
        
        return prev[W];
        
    }
};
