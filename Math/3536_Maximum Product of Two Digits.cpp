// 3536. Maximum Product of Two Digits

// Method : 1
void solve(int n, vector<int>&temp){
    while(n>0){
    int last = n%10;
    temp.push_back(last);
        n = n/10;
    }
}
class Solution {
public:
    int maxProduct(int n) {
        vector<int>temp;
        solve(n,temp);

        sort(temp.begin(), temp.end(), greater<int>());
        return temp[0]*temp[1];
    }
};


// Method : 2
class Solution {
public:
    int maxProduct(int n) {
        
        string s = to_string(n);
        sort(s.rbegin() , s.rend());
        int maxProduct = (s[0]-'0')*(s[1]-'0');
        return maxProduct;
    }
};
