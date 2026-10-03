// 32. Longest Valid Parentheses

void checkinvalid(string s,int n, stack<int>st, vector<bool>&check){
    for(int i=0; i<n; i++){

        if(!st.empty() && s[i] == ')'){
            if(s[st.top()] == '('){
                st.pop();
                continue;
            }
        }
        st.push(i);
    }

    while(!st.empty()){
        check[st.top()] = 1;
        st.pop();
    }
}
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        if(n == 0 || n == 1) return 0;

        stack<int>st1;
        vector<bool>check(n);
        checkinvalid(s,n, st1, check);

        stack<char>st;
        
        int totalcount = 0;
        int count = 0;

        for(int i=0; i<n; i++){

            if(!st.empty() && s[i] == ')'){
                if(st.top() == '('){
                    count += 2;
                    totalcount = max(totalcount,count);
                    st.pop();
                    continue;
                }
                else{
                    count = 0;
                }
            }
            
            if(check[i] == 1){
                count = 0;
            }
            st.push(s[i]);
        }

        return totalcount;
    }
};
