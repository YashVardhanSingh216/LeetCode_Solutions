// 1621. Number of Sets of K Non-Overlapping Line Segments

// TLE :-

// int Solve(int n,int k,int i,int M, vector<vector<int>>&dp){

//     if(k == 0)
//     return 1;

//     if(i >= n)
//     return 0;

//     if(dp[i][k] != -1) 
//     return dp[i][k];

//     // Skip the current point
//     long long skip = Solve(n,k,i+1,M,dp) % M;

//     // take the current point
//     long long take = 0;
//     for(int j=i+1; j<=n-1; j++){
//         take += Solve(n,k-1,j,M,dp) % M;
//     }

//     return dp[i][k] = (skip + take) % M;
// }
class Solution {
public:
    int numberOfSets(int n, int k) {

        int M = 1e9 + 7;

        // vector<vector<int>>dp(n, vector<int>(k+1, -1));
        // return Solve(n,k,0,M,dp) % M;
        
        vector<vector<int>>dp(n+1, vector<int>(k+1, 0));

        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }


        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=k; j++){

                long long skip = (dp[i+1][j]) % M;
                long long take = 0;

                for(int k=i+1; k<n; k++){
                    take += (dp[k][j-1]) % M;
                }

            dp[i][j] = (take + skip) % M;

            }
        }
        
        return dp[0][k];
    }
};
