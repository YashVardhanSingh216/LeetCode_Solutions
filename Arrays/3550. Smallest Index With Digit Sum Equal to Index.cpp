// 3550. Smallest Index With Digit Sum Equal to Index

int giveSum(int k){

    int sum = 0;

    while(k > 0){
        sum += k%10;
        k/=10;
    }
    return sum;
}
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0; i<n; i++){

            int sum = giveSum(nums[i]);

            if(sum == i){
                return i;
            }
        }

        return -1;
    }
};
