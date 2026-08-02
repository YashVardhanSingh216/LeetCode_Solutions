// 115. Distinct Subsequences


//  TOP DOWN :
int subseq(int n,int m,string &s,string &t,vector<vector<int>>&dp){

    if(m == 0) return 1;
    if(n == 0) return 0;
    if(dp[n][m] != -1) return dp[n][m];

    if(s[n-1] == t[m-1])
    return dp[n][m] = subseq(n-1,m,s,t,dp) + subseq(n-1,m-1,s,t,dp);

    return dp[n][m] = subseq(n-1,m,s,t,dp);
}
class Solution {
public:

    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return subseq(n,m,s,t,dp);

        // SPACE OPTIMIZATION:

        // n -> i : 0 -> n-1
        // m -> j : 0 -> m-1

        // vector<int>prev(m+1,0);
        // prev[0] = 1;
        // // for(int i=0; i<=n; i++){
        // //     prev[0] = 1;
        // // }

        // for(int i=1; i<=n; i++){
        //     vector<int>curr(m+1);
        //     curr[0] = 1;

        //     for(int j=1; j<=m; j++){
        //         if(s[i-1] == t[j-1])
        //         curr[j] = prev[j] + prev[j-1];

        //         else
        //         curr[j] =prev[j];
        //     }
        //     prev = curr;
        // }
        
        // return prev[m];
    }
};
