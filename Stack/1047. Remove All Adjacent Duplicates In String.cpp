// 1047. Remove All Adjacent Duplicates In String

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();

        stack<pair<char,int>>st;
        st.push({s[0], 1});

        string ans = "";

        for(int i=1; i<n; i++){

            if(!st.empty() && s[i] == st.top().first){
                st.pop();
            }
            else{

                st.push({s[i],1});
            
            }

        }

        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};
