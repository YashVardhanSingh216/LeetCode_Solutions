// 3517. Smallest Palindromic Rearrangement I

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(s.size() == 1) return s;

        if(s.size() % 2 == 0){

            vector<int>nums(s.size());

            for(int i=0; i<s.size(); i++){
                nums[i] = int(s[i]);

            }
            sort(nums.begin(), nums.end());

            string ans = "";

            for(int i=0; i<nums.size(); i=i+2){
                ans += char(nums[i]);
            }
            cout<<ans<<endl;;
            string rev = ans;
            reverse(rev.begin(),rev.end());
        return ans+rev;
    }

    else{

        int mid = s.size()/2;
        cout<<s[mid];

        vector<int>nums(s.size());

        for(int i=0; i<s.size(); i++){
            nums[i] = int(s[i]);

        }
        sort(nums.begin(), nums.end());

        string ans = "";

        for(int i=1; i<nums.size(); i=i+2){
            ans += char(nums[i]);
        }
        // cout<<ans<<endl;;
        string rev = ans;
        reverse(rev.begin(),rev.end());
        return ans+s[mid]+rev;
        

    }
       

    }
};
