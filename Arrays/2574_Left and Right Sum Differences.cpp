// 2574. Left and Right Sum Differences

void solve(int n, vector<int>&nums, vector<int>&leftSum){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        leftSum[i] = sum - nums[i];
    }
}
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftSum(n,0);
        vector<int>rightSum(n,0);

        solve(n,nums,leftSum);
        reverse(nums.begin(), nums.end());
        solve(n,nums,rightSum);
        reverse(rightSum.begin(), rightSum.end());
        
        for(int i=0; i<n; i++){
            leftSum[i] = abs(leftSum[i] - rightSum[i]);
        }

        return leftSum;

    }
};
