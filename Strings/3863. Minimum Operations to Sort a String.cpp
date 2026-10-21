// 3863. Minimum Operations to Sort a String

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        char mn = 'z',mx = 'a';
        int mn_idx = -1,mx_idx = -1;
        unordered_map<char,int>mp;


        for(int i=0; i<n; i++){
            if(s[i] < mn){
                mn = s[i];
                mn_idx = i;
            }
            if(s[i] >= mx){
                mx = s[i];
                mx_idx = i;
            }

            mp[s[i]]++;
        }

        string k = s;
        sort(k.begin(),k.end());
        if(s == k){
            // cout<<0<<endl;
            return 0;
        }

        if(n == 2 && k!=s){
            // cout<<-1<<endl;
            return -1;
        } 

        if(mn_idx == 0 || mx_idx == n-1){
        // cout<<1<<endl;
        return 1;
        }

        if((mx_idx == 0 && mp[mx] == 1) && (mn_idx == n-1 && mp[mn] == 1)){
            // cout<<3<<endl;
            return 3;
        }

        return 2;
    }
};
