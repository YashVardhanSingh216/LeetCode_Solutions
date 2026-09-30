// 334. Increasing Triplet Subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        int first = INT_MAX;
        int second = INT_MAX;

        for(int i=0; i<n; i++){

            if(nums[i] < first)
            first = nums[i];

            else if(nums[i] < second){
                if(nums[i] > first)
                second = nums[i];
            }

            else{
                if(nums[i] > second)
                return true;
            }
        }

        return false;


    }
};
