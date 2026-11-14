// 3364. Minimum Positive Sum Subarray 

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int sum = INT_MAX;

        for(int i=0; i<n; i++){
            int tempSum = 0;
            int size = 0;
            for(int j=i; j<n; j++){

                if(size > r) break;

                tempSum += nums[j];
                size = j - i + 1;

                if((size >= l && size <= r) && tempSum > 0){
                    sum = min(sum , tempSum);
                }

            }
        }

        return (sum > 0 && sum != INT_MAX) ? sum : -1;

    }
};
