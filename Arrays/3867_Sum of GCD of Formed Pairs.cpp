// 3867. Sum of GCD of Formed Pairs

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGcd(n);
        int mx = INT_MIN;

        for(int i=0; i<n; i++){
            mx = max(mx,nums[i]);
            prefixGcd[i] = __gcd(nums[i],mx);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        long long start = 0;
        long long end = n-1;
        long long sum = 0;

        while(start < end){
            long long gcd = __gcd(prefixGcd[start],prefixGcd[end]);
            sum += gcd;
            start++;
            end--;
        }

        return sum;

    }
};
