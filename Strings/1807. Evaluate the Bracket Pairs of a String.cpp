// 1807. Evaluate the Bracket Pairs of a String

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {

        int n = s.size();

        unordered_map<string,string>mp;

        for(int i=0; i<k.size(); i++){
            mp[k[i][0]] = k[i][1];
        }

        string ans = "";
        for(int i=0; i<n; i++){

            if(s[i] == '('){

                int j = i+1;
                string temp = "";
                while(s[j] != ')'){
                    temp += s[j];
                    j++;
                }

                if(mp.count(temp)){
                    cout<<temp<<" "<<mp[temp]<<" "<<endl;
                    ans += mp[temp];
                }
                else
                ans += "?";

                i = j;
            }
            
            if(s[i] != ')')
            ans += s[i];

        }

        return ans;

    }
};
