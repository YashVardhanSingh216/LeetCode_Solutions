// 162. Find Peak Element

void BinarySearch(vector<int>&nums,int n,int low,int high, int &ans){

    while(low <= high){

        int mid = low + (high - low)/2;

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            ans = mid;
            return;
        }

        else if(nums[mid] >= nums[mid-1]){
            low = mid;
        }

        else{
            high = mid;
        }
    }
}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 0;
        }

        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n-1] > nums[n-2]){
            return n-1;
        }
        int ans = -1;

        BinarySearch(nums,n,0,n-1,ans);  
        return ans;      
    }
};
