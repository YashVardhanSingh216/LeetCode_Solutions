// 647. Palindromic Substrings

// bool checkPalindrome(string s,int size){

//     int start = 0;
//     int end = size - 1;

//     while(start < end){
//         if(s[start] != s[end]){
//             return false;
//         }
//         if(s[start]==s[end]){
//             start++;
//             end--;
//         }
//     }
//     return true;
// }
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int countPalin = 0;
        for(int i=0; i<n; i++){

            // odd length string
            int left = i, right = i;

            while(left>=0 && right<n){
                if(s[left] == s[right]){
                    left--;
                    right++;
                    countPalin++;
                }
                else{
                    break;
                }
            }


            //even length string
            int start = i, end = i+1;

            while(start >= 0 && end < n){
                if(s[start] == s[end]){
                    start--;
                    end++;
                    countPalin++;
                }
                else{
                    break;
                }
            }
        }
        return countPalin;

        // vector<string>substring;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<=n; j++){
        //         string k = s.substr(i,j-i);
        //         substring.push_back(k);
        //     }
        // }        
        // for(auto x : substring){
        //     // cout<<x<<" ";
        //     int size = x.size();

        //     if(size == 1){
        //         countPalin++;
        //     }
        //     else if(x[0] == x[size-1]){
        //         if(checkPalindrome(x,size))
        //         countPalin++;
        //     }
        // }
        // return countPalin;
    }
};
