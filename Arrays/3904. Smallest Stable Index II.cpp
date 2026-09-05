// 3904. Smallest Stable Index II

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>maxi(n,INT_MIN); maxi[0] = nums[0];
        vector<int>mini(n,INT_MAX); mini[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            maxi[i] = max(maxi[i-1],nums[i]);
        }

        for(int i=n-2; i>=0; i--){
        mini[i] = min(mini[i+1],nums[i]);
        }

        int ans = -1;

        for(int i=0; i<n; i++){

            if(maxi[i] - mini[i] <= k){
                ans = i;
                break;
            }
        }

        return ans;

    }
};
