// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size();
        int left = 0;
        int s_sum = accumulate(nums.begin(),nums.begin()+k,0);
        int s_avg = s_sum/k;

        int ans = 0;
        if(s_avg >= threshold)
        ans++;

        int p_sum = s_sum;
        for(int i=k; i<n; i++){
            int sum = p_sum - nums[left] + nums[i];
            int avg = sum/k;

            if(avg >= threshold){
                ans++;
            }
            left++;
            p_sum = sum;

        }  

        return ans;     
    }
};
