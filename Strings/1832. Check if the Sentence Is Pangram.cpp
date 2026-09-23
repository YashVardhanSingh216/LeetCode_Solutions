// 1832. Check if the Sentence Is Pangram

class Solution {
public:
    bool checkIfPangram(string s) {

        vector<bool>check(26,0);

        int n = s.size();

        for(int i=0; i<n; i++){

            check[s[i] - 'a'] = true;
        }

        for(int i=0; i<26; i++){
            if(check[i] == false)
            return false;
        }

        return true;
    }
};
