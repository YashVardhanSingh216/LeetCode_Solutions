// 2089. Find Target Indices After Sorting Array

void BinarySearch(vector<int>&nums,vector<int>&ans,int &target){

    int start = 0;
    int end = nums.size()-1;
    int first = -1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                first = mid;
                end = mid-1;

            }

            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }

        }
        if(first != -1){
            for(int i=first; i<nums.size() && nums[i] == target; i++){
                ans.push_back(i);
            }
        }

}
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int>ans;

        sort(nums.begin(),nums.end());
        BinarySearch(nums,ans,target);
        sort(ans.begin(),ans.end());

        return ans;
    }
};
