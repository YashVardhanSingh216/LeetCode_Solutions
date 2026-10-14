// 3723. Maximize Sum of Squares of Digits

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if(num*9 < sum)
        return "";

        string ans = "";
        while(num > 0 && sum >= 9){
            ans += '9';
            sum -= 9;
            num--;
        }
        if(num > 0 && sum < 10){
            ans += (sum + '0');
            num--;
        }
        while(num > 0){
            ans += '0';
            num--;
        }


        return ans;




        // int digitsSum(int n){
        
        //     int sum = 0;
        //     while(n > 0){
        //         sum += n%10;
        //         n/=10;
        //     }
        //     return sum;
        // }
        

        // int start = pow(10,num-1);
        // int end = pow(10,num) - 1;

        // int ans = 0;

        // for(int i = end; i>=start; i--){

        //     int s = digitsSum(i);

        //     if(s == sum){
        //         ans = i;
        //         break;
        //     }
        // }

        // string k = "";

        // if(ans != 0){
        //     k = to_string(ans);
        //     return k;
        // }
        // return k;


    }
};
