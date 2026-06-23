// 2390. Removing Stars From a String

class Solution {
public:
    string removeStars(string s) {
        stack<char>st;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '*') {
                st.pop();
            }
            else st.push(s[i]);

        }

        stack<char>rev;

        while(!st.empty()){
            rev.push(st.top());
            st.pop();
        }

        string ans = "";

        while(!rev.empty()){
            ans+=rev.top();
            rev.pop();
        }

        return ans;

    }
};
