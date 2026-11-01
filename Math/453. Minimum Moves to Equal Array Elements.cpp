// 453. Minimum Moves to Equal Array Elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == mini)
                continue;

            else {
                sum += (nums[i] - mini);
            }
        }
        return sum;
    }
};
