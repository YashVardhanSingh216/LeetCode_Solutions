// 40. Combination Sum II

void solve(int idx,int n,vector<int>&nums,int target,vector<vector<int>>&ans,vector<int>&temp){

    if(target == 0){
        ans.push_back(temp);
        return;
    }

    for(int i=idx; i<n; i++){

        if(nums[i] > target) break;
        if(i > idx && nums[i] == nums[i-1]) continue;
        temp.push_back(nums[i]);
        solve(i+1,n,nums,target - nums[i],ans,temp);
        temp.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;

        sort(candidates.begin(),candidates.end());
        solve(0,n,candidates,target,ans,temp);

        return ans;
        
        // set<vector<int>>st(ans.begin(), ans.end());

        // vector<vector<int>>result;
        // for(auto x : st){
        //     result.push_back(x);
        // }

        // return result;
    }
};
