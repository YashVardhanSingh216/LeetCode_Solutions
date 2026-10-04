bool checkValid(string &s,int n,int index, int open, vector<vector<int>>&dp){

    if(index >= n){
        return open == 0;
    }
    if(open < 0)
    return false;

    if(dp[index][open] != -1) 
    return dp[index][open];

    if(s[index] == '('){
    return dp[index][open] = checkValid(s,n, index+1, open + 1,dp);
    }
    else if(s[index] == ')'){
    return dp[index][open] = checkValid(s,n, index+1, open - 1,dp);
    }
    else{
        bool o = checkValid(s,n, index+1, open + 1,dp); // open
        bool c = checkValid(s,n, index+1, open - 1,dp); // close
        bool e = checkValid(s,n, index+1, open,dp); // empty
        return dp[index][open] = o || c || e;
    }
}

class Solution {
public:
    bool checkValidString(string s) {

        int n = s.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return checkValid(s,n,0,0,dp);
        
    }
};
