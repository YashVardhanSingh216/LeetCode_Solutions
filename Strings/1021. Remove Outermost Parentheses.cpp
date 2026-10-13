// 1021. Remove Outermost Parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        int open = 0;
        string k = "";

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                open++;

                if(open > 1){
                    k += s[i];
                }
            }
            else{
                if(open > 1){
                    k += s[i];
                }
                open--;
            }

        }

        return k;
    }
};
