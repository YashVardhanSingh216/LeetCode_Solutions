// 49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<string>temp = strs;
        int n = strs.size();

        // sorted , real
        vector<pair<string,string>>str;
        for(int i=0; i<n; i++){

            sort(temp[i].begin(),temp[i].end());
            str.push_back({temp[i],strs[i]});

        }
        sort(str.begin(),str.end());

        for(int i=0; i<n; i++){

            cout<<"{"<<str[i].first<<","<<str[i].second<<"}"<<" ";
        }

        vector<vector<string>>ans(n);
        ans[0].push_back(str[0].second);

        int curr = 0;
        int start = 1;

        while(start < temp.size()){


            if(str[start].first == str[start-1].first){
                ans[curr].push_back(str[start].second);
                start++;
            }
            else{
                curr++;
                ans[curr].push_back(str[start].second);
                start++;
            }
        }

        ans.resize(curr+1);
        return ans;

    }
};
