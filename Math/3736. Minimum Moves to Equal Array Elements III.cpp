// 3736. Minimum Moves to Equal Array Elements III

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += (maxi - nums[i]);
        }

        return sum;

    }
};
