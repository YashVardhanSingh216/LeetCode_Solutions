// 66. Plus One

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        if(digits[n-1] != 9){
            vector<int>ans(n,0);

            for(int i=0; i<n-1; i++){
                ans[i] = digits[i];
            }
            ans[n-1] = digits[n-1] + 1;

            for(int i=0; i<n; i++){
                cout<<ans[i]<<" ";
            }
            return ans;
        }

        else{
            vector<int>ans;
            reverse(digits.begin(),digits.end());
            int carry = 1;

            for(int i=0; i<n; i++){
                if(digits[i] == 9 && carry == 1){
                    ans.push_back(0);
                }
                else if(digits[i] != 9 && carry == 1){
                    ans.push_back(digits[i] + 1);
                    carry = 0;
                }
                else{
                    ans.push_back(digits[i]);
                }
            }
            int sum = accumulate(digits.begin(),digits.end(),0);
            if(sum == n*9)
            ans.push_back(1);
            
            reverse(ans.begin(),ans.end());

            for(int i=0; i<n; i++){
                cout<<ans[i]<<" ";
            }

            return ans;
        }
    }
};
