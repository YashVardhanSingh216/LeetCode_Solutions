// 2914. Minimum Number of Changes to Make Binary String Beautiful

class Solution {
public:
    int minChanges(string s) {
        int n = s.size();

        int count = 0;

        for (int i = 1; i < n; i++) {
            char prev = s[i - 1];
            char curr = s[i];

            if ((prev != curr) && (i % 2 != 0)) {
                curr = prev;
                count++;
            }
        }
        return count;
    }
};
