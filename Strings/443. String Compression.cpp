// 443. String Compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        vector<pair<char,int>>s;

        int count = 1;
        for(int i=1; i<n; i++){
            if(chars[i] == chars[i-1]){
                count++;
            }
            else{
                s.push_back({chars[i-1],count});
                count = 1;
            }
        }
        s.push_back({chars[n-1],count});

        string ans = "";

        for(auto x : s){
            ans += x.first;

            if(x.second > 1){
                int val = x.second;
                ans += to_string(val);
            }
        }

        for(int i=0; i<n; i++){
            if(i < ans.size())
            chars[i] = ans[i];

            else
            chars.pop_back();
        }

        return chars.size();
    }
};
