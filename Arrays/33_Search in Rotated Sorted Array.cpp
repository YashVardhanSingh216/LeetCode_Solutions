// 33. Search in Rotated Sorted Array

int RotatedBinarySearch(int left,int right,vector<int>&arr,int target){

    while(left <= right){

        int mid = left + (right - left)/2;

        if(arr[mid] == target) return mid;
        
        // left sorted array
        if(arr[left] <= arr[mid]){
            if(target >= arr[left] && target <= arr[mid]) right = mid - 1;

            else left = mid + 1;
        }
        else{
            if(target >= arr[mid] && target <= arr[right]) left = mid+1;

            else right = mid - 1;
        }
    }

    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;

        return RotatedBinarySearch(left,right,nums,target);
    }
};
