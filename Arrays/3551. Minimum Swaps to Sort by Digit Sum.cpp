// 3551. Minimum Swaps to Sort by Digit Sum

int digitSum(int n){
    int sum = 0;

    while(n > 0){
        sum += n%10;
        n/=10;
    }
    return sum;
}
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        vector<tuple<int,int,int>>temp(n);

        for(int i=0; i<n; i++){
            temp[i] = {digitSum(nums[i]), nums[i], i};
        }
        sort(temp.begin(),temp.end());

            int swapped = 0;
        for(int i=0; i<n; i++){
            if(get<2>(temp[i]) == i){
                continue;
            }
            else{
                swap(temp[i],temp[get<2>(temp[i])]);
                swapped++;
                i--;
            }
        }
        return swapped;
    }
};
