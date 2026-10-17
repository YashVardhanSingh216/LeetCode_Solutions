// 15. 3Sum

void twoSum(vector<int>&nums, int curr,int i,int j, set<vector<int>>&ans){

    int totalSum = 0;
    while(i < j){
        totalSum = nums[i] + nums[j] + curr;
        if(totalSum == 0){
            ans.insert({curr, nums[i], nums[j]});
            i++;
            j--;
        }
        else if(totalSum < 0){
            i++;
        }
        else{
            j--;
        }
    }
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        set<vector<int>>temp;
        vector<vector<int>>ans;

        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int curr = nums[i];
            twoSum(nums,curr,i+1,n-1,temp);
        }


        for(auto y : temp){
            ans.push_back({y});
        }

        return ans;


    }
};
