// 3014. Minimum Number of Pushes to Type Word I

class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.size();

        if(n <= 8) return n;

        int sum = 8;
        int last = n - (n - 8);

        for(int i=last; i<n; i++){

            if(i>=8 && i<=15) sum+=2;

            else if( i>=16 && i<=23) sum+=3;

            else sum+=4;
        }

        return sum;
    }
};
