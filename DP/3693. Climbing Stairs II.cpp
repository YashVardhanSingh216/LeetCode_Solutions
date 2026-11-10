// 3693. Climbing Stairs II

// int climbStair(int i, vector<int>& costs, int n, vector<int>& dp) {

//     if (i >= n) {
//         return 0;
//     }

//     if (dp[i] != -1)
//         return dp[i];

//     int first = INT_MAX;
//     int second = INT_MAX;
//     int third = INT_MAX;

//     if (i + 1 <= n)
//         first = costs[i + 1] + 1 + climbStair(i + 1, costs, n, dp);

//     if (i + 2 <= n)
//         second = costs[i + 2] + 4 + climbStair(i + 2, costs, n, dp);

//     if (i + 3 <= n)
//         third = costs[i + 3] + 9 + climbStair(i + 3, costs, n, dp);

//     return dp[i] = min({first, second, third});
// }

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0);
        // vector<int>dp(n+1,-1);
        // return climbStair(0,costs,n,dp);

        vector<int> dp(n + 1, 0);

        int first = INT_MAX;
        int second = INT_MAX;
        int third = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 <= n)
                first = costs[i + 1] + 1 + dp[i + 1];

            if (i + 2 <= n)
                second = costs[i + 2] + 4 + dp[i + 2];

            if (i + 3 <= n)
                third = costs[i + 3] + 9 + dp[i + 3];

            dp[i] = min({first, second, third});
        }

        return dp[0];
    }
};
