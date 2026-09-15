// 1209. Remove All Adjacent Duplicates in String II

// OPTIMAL SOLUTION :-

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.size();
        stack<pair<char,int>>st;
        st.push({s[0],1});

        for(int i=1; i<n; i++){

            if(!st.empty() && (s[i] == st.top().first)){
                st.top().second++;
                
                if(st.top().second == k)
                st.pop();
            }

            else
            st.push({s[i],1});
        }

        string ans  = "";

        while(!st.empty()){
            int count = st.top().second;
            while(count--){
                ans += st.top().first;
            }
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        // cout<<ans;
        return ans;
    }
};



// TLE :-
// void integrate(string &s,int k){

//     while(true){
//     int n = s.size();
//     int i = 0;
//     string str = "";

//     while(i < n){

//         int count = 1;

//         while(i + count < n && s[i] == s[i+count]) count++;

//         if(count >= k) i+=k;

//         else{
//             for(int j=i; j<i+count; j++){
//                 str += s[j];
//             }
//             i+=count;
//         }
//     }

//     if(str == s) break;

//     s = str;
    
//     }
// }

// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         integrate(s,k);

//         return s;
//     }
// };
