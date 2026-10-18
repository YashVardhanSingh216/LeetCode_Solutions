// 231. Power of Two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        // if(n == 1)
        // return true;
        // for(int i=1; i<=ceil(sqrt(n)); i++){
        //     if(pow(2,i) == n){
        //         return true;
        //     }
        // }
        // return false;
        return n > 0 && (n & (n - 1)) == 0;
    }
};
