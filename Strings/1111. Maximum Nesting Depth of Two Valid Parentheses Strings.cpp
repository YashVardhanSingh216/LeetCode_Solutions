// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings

class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n = s.size();

        stack<int>st;

        vector<int>ans(n);
        int curr = -1;

        for(int i=0; i<n; i++){

            if(s[i] == '('){
                curr++;
                ans[i] = curr%2;
                st.push(curr);
            }
            if(s[i] == ')'){
                ans[i] = st.top()%2;
                curr = st.top()-1;
                st.pop();
            }
        }

        return ans;
    }
};
