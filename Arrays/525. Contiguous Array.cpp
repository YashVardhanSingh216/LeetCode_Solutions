// 525. Contiguous Array.cpp

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        unordered_map<int, int> mp;
        mp[0] = -1;

        int count = 0;

        for (int i = 0; i < n; i++) {

            if (mp.find(prefix[i]) != mp.end()) {
                count = max(count,i - mp[prefix[i]]);
                
            } else {
                mp[prefix[i]] = i;
            }
        }
        return count;
    }
};
