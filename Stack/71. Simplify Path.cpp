// 71. Simplify Path

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string s = "";

        for(int i=0; i<n; i++){
            if(path[i] == '/' && path[i+1] == '/')
            continue;

            else
            s += path[i];
        }

        int size = s.size();
        stack<string>st;

        for(int i=size-1; i>=0; i--){
            string k = "";
            int idx = i;

            while(s[idx] != '/' && idx >= 0){
                k += s[idx];
                idx--;
            }
            if(!k.empty()){
                reverse(k.begin(),k.end());
                st.push(k);
            }

            i = idx;
        }

        stack<string>temp;

        while(!st.empty()){

            string curr = st.top();
            st.pop();

            if(curr == ".."){
                if(!temp.empty())
                temp.pop();

                continue;
            }
            if(curr == "."){
                continue;
            }

            temp.push(curr);

        }

        string ans = "";

        while(!temp.empty()){
            ans = "/" + temp.top() + ans;
            temp.pop();
        }

        if(ans == "") return "/";

        return ans;
    }
};
