// 2904. Shortest and Lexicographically Smallest Beautiful String

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();
        int size = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;
        int bestStart = -1;

        while(end < n){
            sum += s[end]-'0';

            while(sum == k){
                int currSize = end - start + 1;

                if((currSize < size) || 
                (currSize == size) && 
                (s.substr(start,currSize) < s.substr(bestStart,size))){
                    size = currSize;
                    bestStart = start;
                }
                sum -= s[start]-'0';
                start++;
            }
            end++;
        }
        
        if(bestStart == -1)
        return "";

        if(size == INT_MAX)
        return "";

        string ans = s.substr(bestStart,size);
        return ans;
    }
};
