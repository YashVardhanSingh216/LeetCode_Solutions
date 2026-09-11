// 43. Multiply Strings

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();

        if((num1[0] - '0' == 0) || (num2[0] - '0' == 0)) return "0";

        vector<vector<int>>result;

        for(int i=n2-1; i>=0; i--){
            int carry = 0;
            vector<int>temp;

            for(int j=n1-1; j>=0; j--){
                int prod = (num2[i] - '0')*(num1[j] - '0') + carry;
                temp.push_back(prod % 10);
                carry = prod/10;

            }
            if(carry)
            temp.push_back(carry);

            result.push_back(temp);

            for(int k=n2-1-i; k>0; k--){
                result.back().insert(result.back().begin(), 0);
            }
        }

        int n = 0;

        for(auto &v : result)
            n = max(n, (int)v.size());

        string ans = "";
        int carry = 0;

        for(int j = 0; j < n; j++){

            int sum = carry;

            for(int i = 0; i < result.size(); i++){

                if(j < result[i].size())
                    sum += result[i][j];
            }

            ans += (sum % 10) + '0';
            carry = sum / 10;
        }

        if(carry)
            ans += carry + '0';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
