// 3963. Create Grid With Exactly One Path

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));

        for (int i = 0; i < m; i++) {
            ans[i][n - 1] = '.';
        }
        for (int i = 0; i < n; i++) {
            ans[0][i] = '.';
        }
        return ans;


      // for(int i=0; i<m; i++){
      //     string s = "";
          
      //     for(int j=0; j<n; j++){
      //         if(i == 0){
      //             s += '.';
      //         }
  
      //         else if(j == n-1){
      //             s += '.';
      //         }
  
      //         else{
      //             s += '#';
      //         }
      //     }
      //     ans.push_back(s);
      // }
      // return ans;
      
    }
};
