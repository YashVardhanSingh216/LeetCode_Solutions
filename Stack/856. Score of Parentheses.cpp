// 856. Score of Parentheses

class Solution {
public:
    int scoreOfParentheses(string s) {

        int n = s.size();

        stack<int>st;

        int score = 0;
        
        for(int i=0; i<n; i++){

            if(s[i] == '('){
                st.push(score);
                score = 0;
            }
            else{ // ')'

                if(s[i-1] == '('){ // ()
                    score = 1 + st.top();
                }
                else{  // ))
                    score = 2*score + st.top();
                }
                st.pop();
            }
        }
        return score;
            
    }
};
