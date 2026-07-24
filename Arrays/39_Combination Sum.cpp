// 39. Combination Sum

void solve(int idx,int n,vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&temp){

    if(target == 0){
        ans.push_back(temp);
        return;
    }
    

    for(int i=idx; i<n; i++){
        if(target < candidates[i]) continue;
        // if(i>idx && candidates[i] == candidates[i-1]) continue;
        if(target >= candidates[i]){
            temp.push_back(candidates[i]);
            solve(i,n,candidates,target - candidates[i],ans,temp);
            temp.pop_back();   
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;

        solve(0,n,candidates,target,ans,temp);
        return ans;
    }
};
