// 643. Maximum Average Subarray I

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        // int start = 0;
        // int end = k-1;
        // int sum = INT_MIN;

        // if(k > n) return 0;

        // while(end < n){
        //     sum = max(sum,accumulate(nums.begin()+start,nums.begin()+end+1,0));
        //     start++;
        //     end++;
        // }

        // double ans = (double)sum/k;

        // return ans;

        int sum = 0;

        for(int i=0; i<k; i++){
            sum += nums[i];
        }

        int maxSum = sum;

        for(int i=k;i<n;i++){
            sum += nums[i];
            sum -= nums[i-k];

            maxSum = max(maxSum,sum);
        }

        double ans = double(maxSum)/k;

        return ans;
    }
};
