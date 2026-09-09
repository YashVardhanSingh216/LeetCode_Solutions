// 41. First Missing Positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(nums[i] < mini && nums[i] > 0)
            mini = nums[i];
        }
        if(mini > 1) return 1;

        int limit = n + mini;
        int ans = mini;
        for(int i=mini; i<=limit; i++){
            if(mp[i] == 0){
                ans = i;
                break;
            }
        }
        return ans;

    }
};
