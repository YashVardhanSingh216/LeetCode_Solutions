// 678. Valid Parenthesis String

class Solution {
public:
    bool checkValidString(string s) {

        int n = s.size();
        if(n == 1 && s[0] != '*') return false;
        if(n == 1 && s[0] == '*') return true;

        int open = 0;
        int close = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '*') open++;

            else
            open--;
            if(open < 0) return false;
        }

        for(int i=n-1; i>=0; i--){
            if(s[i] == ')' || s[i] == '*') close++;

            else
            close--;
            if(close < 0) return false;
        }


        return true;
    }
};
