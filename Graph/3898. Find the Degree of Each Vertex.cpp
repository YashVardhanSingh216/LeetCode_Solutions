// 3898. Find the Degree of Each Vertex

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix.size();

        for(int i=0; i<n; i++){
            int sum = accumulate(matrix[i].begin(),matrix[i].end(),0);
            ans.push_back(sum);
        }

        return ans;
    }
};
