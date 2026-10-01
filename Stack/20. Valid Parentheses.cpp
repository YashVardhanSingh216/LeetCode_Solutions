// 20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        if(n == 1) 
        return false;

        if(s[0] == ')' || s[0] == ']' || s[0] == '}')
        return false;

        stack<char>st;

        for(int i=0; i<n; i++){

            if(!st.empty()){
                if( st.top() == '(' && s[i] == ')' ){
                st.pop();
                continue;
                }

                if(st.top() == '[' && s[i] == ']'){
                st.pop();
                continue;
                }

                if(st.top() == '{' && s[i] == '}'){
                st.pop();
                continue;
                }
            }

            st.push(s[i]);

        }

        return st.empty() ? true : false;
    }
};
