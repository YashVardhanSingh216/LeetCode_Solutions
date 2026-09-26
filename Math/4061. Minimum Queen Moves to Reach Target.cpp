// 4061. Minimum Queen Moves to Reach Target

class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {

        int s1 = source[0];
        int s2 = source[1];
        int t1 = target[0];
        int t2 = target[1];

        // source and target are same
        if(s1 == t1 && s2 == t2)
        return 0;

        // same row , // same col
        if(s1 == t1 || s2 == t2)
        return 1;
        
        // same diag
        int s = s1+s2;
        int t = t1 + t2;
        if(s == t) return 1;

        if(s > t){
            while(s1 >= 0 && s2 >= 0){
                s1--;
                s2--;

                if(s1 == t1 && s2 == t2)
                return 1;
            }
        }
        if(s < t){
            while(s1 <= 8 && s2 <= 8){
                s1++;
                s2++;

                if(s1 == t1 && s2 == t2)
                return 1;
            }
        }

        return 2;
    }
};
