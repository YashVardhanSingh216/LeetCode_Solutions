// 3718. Smallest Missing Multiple of K

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        int curr = k;

        while(curr <= n*curr){
            if(mp[curr] >= 1){
                curr = curr+k;
            }
            else{
                break;
            }
        }

        return curr;
    }
};
