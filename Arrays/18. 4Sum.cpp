// 18. 4Sum

void twoSum(vector<int>&nums,int i,int j,int s, int e,int target,set<vector<int>>&ans){

    while(i < j){
        long long totalSum = (long long)nums[i] + nums[j] + nums[s] + nums[e];
        if(totalSum == target){
            ans.insert({nums[s],nums[e],nums[i],nums[j]});
            i++;
            j--;
        }
        else if(totalSum < target){
            i++;
        }
        else{
            j--;
        }
    }
}
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        if(n < 4) return {};
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());

        if(nums[0] >= 0 && nums[0] > target){
            vector<vector<int>>k;
            return k;
        }

        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int curr = nums[i] + nums[j];
                twoSum(nums,j+1,n-1,i,j,target,ans);
            }
        }

        vector<vector<int>>a(ans.begin(),ans.end());

        return a;
    }
};
