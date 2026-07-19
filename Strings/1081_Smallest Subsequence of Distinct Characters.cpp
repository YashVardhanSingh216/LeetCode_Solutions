// 1081. Smallest Subsequence of Distinct Characters

class Solution {
public:
    string smallestSubsequence(string s) {
        
        int n = s.size();
        vector<bool>visited(26,0);
        vector<int>lastIndex(26);

        for(int i=0; i<n; i++){
            lastIndex[s[i] - 'a'] = i;
        }

        string result;

        for(int i=0; i<n; i++){

            if(visited[s[i] - 'a'] == 1) continue;

            while(result.size()>0 && result.back() > s[i] && lastIndex[result.back() - 'a'] > i){
                visited[result.back()- 'a'] = 0;
                result.pop_back();
            }

            result.push_back(s[i]);
            visited[s[i] - 'a'] = 1;

        }

        return result;
    }
};
