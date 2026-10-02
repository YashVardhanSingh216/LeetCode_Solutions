// 22. Generate Parentheses

void generateParentheses(int open, string k, vector<string>&ans, int close){

    if(open == 0 && close == 0){
        ans.push_back(k);
        return;
    }

    if(open > 0){
        // can open again
        generateParentheses(open - 1, k  + "(", ans, close);

    }

    // should be closed
    if(close > open){
        generateParentheses(open , k  + ")", ans, close - 1);
    }

}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string k = "";

        generateParentheses(n, k, ans, n);

        return ans;
    }
};
