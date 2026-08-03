// 44. Wildcard Matching

bool matching(int n,int m,string &s,string &p,vector<vector<int>>&dp){

    if(m == 0 && n == 0)
    return 1;

    if(m == 0)
    return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(n == 0){
        for(int k=0; k<m; k++){
            if(p[k] != '*')
            return dp[n][m] = 0;

        }
        return dp[n][m] = 1;
    }


    if(s[n-1] == p[m-1])
    return dp[n][m] = matching(n-1,m-1,s,p,dp);

    else if(p[m-1] == '?')
    return dp[n][m] = matching(n-1,m-1,s,p,dp);

    else if(p[m-1] == '*')
    return dp[n][m] = matching(n,m-1,s,p,dp) || matching(n-1,m,s,p,dp);

    else 
    return dp[n][m] = 0;
}
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return matching(n,m,s,p,dp);
    }
};
