// 516. Longest Palindromic Subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s, text2 = s;
        reverse(text2.begin(), text2.end());

        int n = text1.size();
        int m = text2.size();

        // SPACE OPTIMIZATION:
        vector<int>prev(m+1,0);

        for(int i=1; i<=n; i++){
            vector<int>curr(m+1,0);
            for(int j=1; j<=m; j++){

                if(text1[i-1] == text2[j-1])
                curr[j] = (1 + prev[j-1]);

                else
                curr[j] = max(prev[j], curr[j-1]);
            }

            prev = curr;
        }

        return prev[m];
        // cout<< prev[m];

    }
};
