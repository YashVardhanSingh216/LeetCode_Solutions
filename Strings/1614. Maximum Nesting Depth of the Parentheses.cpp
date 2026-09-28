// 1614. Maximum Nesting Depth of the Parentheses

class Solution {
public:
    int maxDepth(string s) {

        int n = s.size();
        int count = 0;
        int curr = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
            curr++;
            }

            if(s[i] == ')'){
            count = max(count,curr);
            curr--;
            }
        }

        return count;
        
    }
};
