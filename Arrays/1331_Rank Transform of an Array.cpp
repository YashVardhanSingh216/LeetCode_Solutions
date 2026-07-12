// 1331. Rank Transform of an Array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        vector<pair<int,int>>temp;

        for(int i=0; i<arr.size(); i++){
            temp.push_back({arr[i], i});
        }
        sort(temp.begin(), temp.end());

        vector<int>ans(n,1);
        int assign = 1;

        if(arr.size() == 1) return ans;

        for(int j=0; j<temp.size(); j++){
            int index = temp[j].second;
            ans[index] = assign;

            if(j <= temp.size()-2 && temp[j].first == temp[j+1].first) continue;

            else assign++;
        }

        return ans;
    }
};
