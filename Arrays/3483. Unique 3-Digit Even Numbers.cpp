// 3483. Unique 3-Digit Even Numbers

void all_combinations(vector<int>&digits,string str,set<int> &ans,unordered_map<int,int>&mp){

    if(str.size() == 3){

        if(stoi(str) % 2 == 0 && str[0] != '0')
        ans.insert(stoi(str));

        return;
    }

    for(int j=0; j<digits.size(); j++){
        if(mp[digits[j]] > 0){

            // chosing
            str += (digits[j] + '0');
            mp[digits[j]]--;

            // recurrsion
            all_combinations(digits,str,ans,mp);

            // backtracking
            mp[digits[j]]++;
            str.pop_back();
        }
    }
}
class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int n = digits.size();

        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){
            mp[digits[i]]++;
        }

        set<int>ans;
        string s = "";

        all_combinations(digits,s,ans,mp);

        return ans.size();
        
    }
};
