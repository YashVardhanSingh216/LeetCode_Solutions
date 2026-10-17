// 16. 3Sum Closest

void twoSum(vector<int>&nums, int i, int j, int curr, int target, int &ans, int &absDiff){

    int totalSum = 0;
    while(i < j){
        totalSum = nums[i] + nums[j] + curr;
        if(totalSum == target){
            if(abs(totalSum - target) < absDiff){
                absDiff = abs(totalSum - target);
                ans = totalSum;
            }
            break;
        }
        else if(totalSum < target){
            if(abs(totalSum - target) < absDiff){
                absDiff = abs(totalSum - target);
                ans = totalSum;
            }
            i++;
        }
        else{
            if(abs(totalSum - target) < absDiff){
                absDiff = abs(totalSum - target);
                ans = totalSum;

            }
            j--;
        }
    }
}
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int absDiff = INT_MAX;


        for(int i=0; i<n-1; i++){
            int curr = nums[i];
            twoSum(nums, i+1, n-1,curr, target,ans, absDiff);
        }

        return ans;



    }
};
