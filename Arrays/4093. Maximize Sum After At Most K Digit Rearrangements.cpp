// 4093. Maximize Sum After At Most K Digit Rearrangements

class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>>temp(n);

        for(int i=0; i<n; i++){

            string k = to_string(nums[i]);
            
            temp[i].first = nums[i];

            sort(k.rbegin(),k.rend());

            temp[i].second = stoi(k); 

        }

        sort(temp.begin(), temp.end(),
             [](pair<int, int> a, pair<int, int> b) {
                return a.second - a.first > b.second - b.first;

             });

        long long sum = 0;

        for(int i=0; i<n; i++){

            int original = temp[i].first;
            int rearranged = temp[i].second;

            if(k > 0 && rearranged > original){
                sum += rearranged;
                k--;
            }
            else{
                sum += original;
            }
        }

        return sum;
    }
};
