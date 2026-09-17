// 645. Set Mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<int>ans;
        unordered_map<int,int>mp;
        int left = 1;

        for(int i=1; i<=n; i++){
            mp[i]++;
        }

        for(int i=0; i<n; i++){
            mp[nums[i]]++;

            if(nums[i] == left){
                left++;
            }

            if(mp[nums[i]] > 2){
                ans.push_back(nums[i]);
            }
        }
        ans.push_back(left);
        
        return ans;

        // BEST OPTIMAL APPROACH :-
        
        // The values itself tells which index values are present
        int duplicate = 0;
        for(int i=0; i<n; i++){

            if(nums[abs(nums[i]) - 1] < 0)
            duplicate = abs(nums[i]);

            else
            nums[abs(nums[i]) - 1] *= -1;

        }

        int missing = 0;

        for(int i=0; i<n; i++){

            if(nums[i] > 0){
            missing = i+1;
            break;
            }
        } 

        return vector<int>{duplicate,missing};     

        
    }
};
