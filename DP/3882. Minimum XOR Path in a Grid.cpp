// 3882. Minimum XOR Path in a Grid

void solve(int i, int j, int& row, int& col, vector<vector<int>>& grid,
           int xoro, int& ans, vector<vector<vector<bool>>>&dp) {

    xoro ^= grid[i][j];

    if (i == row - 1 && j == col - 1) {
            ans = min(ans,xoro);

        return;
    }

    if(dp[i][j][xoro] != false)
    return;

    dp[i][j][xoro] = true;

    if (i < row - 1) {
        solve(i + 1, j, row, col, grid, (xoro), ans, dp);
    }
    if (j < col - 1) {
        solve(i, j + 1, row, col, grid, (xoro), ans, dp);
    }
}

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int xoro = 0;
        int ans = INT_MAX;

        // vector<vector<vector<int>>>dp(row+1, vector<vector<int>>(col+1, vector<int>(1024,-1)));
        vector<vector<vector<bool>>>dp(row+1, vector<vector<bool>>(col+1, vector<bool>(1024,false)));
        
        solve(0, 0, row, col, grid, xoro, ans, dp);

        return ans;
    }
};
