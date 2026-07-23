// 17. Letter Combinations of a Phone Number

void solve(int idx, string &digits, unordered_map<char,string>&mp, vector<string>&ans, string &temp){

    if(idx >= digits.size()){
        ans.push_back(temp);
        return;
    }

    char ch = digits[idx];
    string str = mp[ch];

    for(int i=0; i<str.size(); i++){
        temp.push_back(str[i]);
        solve(idx+1,digits,mp,ans,temp);
        temp.pop_back();
    }
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string>ans;
        string temp = "";
        solve(0,digits,mp,ans,temp);
        return ans;
    }
};
