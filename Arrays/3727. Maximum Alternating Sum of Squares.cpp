// 3727. Maximum Alternating Sum of Squares

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long n = nums.size();

        long long mid = (n+1)/2;

        sort(nums.begin(),nums.end(), [](int a, int b){
            return abs(a) > abs(b);
        });

        long long sum = 0;
        for(int i=0; i<n; i++){
            if(mid > 0){
                sum += nums[i]*nums[i];
                mid--;
            }
            else{
                sum-= nums[i]*nums[i];
            }
        }

        return sum;
        
    }
};
