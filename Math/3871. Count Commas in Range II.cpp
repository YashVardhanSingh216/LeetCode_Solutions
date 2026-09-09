// 3871. Count Commas in Range II

class Solution {
public:
    long long countCommas(long long n) {

        long long total = 0;
        long long k = n - 1000 + 1;

        if(k > 0){
            total += k;

            k = n - 1e6 + 1;
            if(k > 0){
                total += k;

                k = n - 1e9 + 1;
                if(k > 0){
                    total += k;

                    k = n - 1e12 + 1;
                    if(k > 0){
                        total += k;

                        k = n - 1e15 + 1;
                        if(k > 0){
                            total += k;
                        }
                    }
                }
            }
        }

        // cout<<total<<endl;
        return total;
    }
};
