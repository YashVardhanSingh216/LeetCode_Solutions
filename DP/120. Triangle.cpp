// 120. Triangle

void solve(int i, int j, int row, vector<vector<int>>&triangle, vector<vector<int>>&dp){

    if(i == row-1){
        dp[i][j] = triangle[i][j];
        return;
    }

    if(dp[i][j] != 1e6) return;


    solve(i+1,j,row,triangle,dp);
    solve(i+1,j+1,row,triangle,dp);

    dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
    
}

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int row = triangle.size();

        vector<vector<int>>dp(row, vector<int>(row,1e6));
        solve(0,0,row,triangle, dp);
        return dp[0][0];
    }
};
