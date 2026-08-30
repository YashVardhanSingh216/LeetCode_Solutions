// 2091. Removing Minimum and Maximum From Array

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1) return 1;

        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());

        int min_idx = 0,max_idx = 0;

        for(int i=0; i<n; i++){

            if(mini == nums[i]){
                min_idx = i;
            }

            if(maxi == nums[i])
            max_idx = i;
        }

        int mostleft = min(min_idx,max_idx);
        int mostright = max(min_idx,max_idx);

        cout<<"Most Left: "<<mostleft<<endl;
        cout<<"Most Right: "<<mostright<<endl;

        int min_del = min( min(mostright + 1,n - mostleft),(mostleft+1) + (n - mostright));

        return min_del;

    }
};
