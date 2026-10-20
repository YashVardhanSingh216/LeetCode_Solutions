// 2231. Largest Number After Digit Swaps by Parity

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        int n = s.size();

        string ans = "";
        string even = "";
        string odd = "";

        for(int i=0; i<n; i++){
            if((s[i] - '0') % 2 == 0){
                even += s[i];
            }
            else{
                odd += s[i];
            }
        }
        sort(even.rbegin(),even.rend());
        sort(odd.rbegin(),odd.rend());  

        int e = 0, o = 0;

        for(int i=0; i<n; i++){
            if((s[i] - '0') % 2 == 0){
                ans += even[e];
                e++;
            }
            else{
                ans += odd[o];
                o++;
            }
        }

        return stoi(ans);           
    }
};
