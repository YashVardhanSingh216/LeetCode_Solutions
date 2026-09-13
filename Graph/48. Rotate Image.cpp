// 48. Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int row = matrix.size();
        int col = matrix[0].size();

        // TRANSPOSE :
        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){

                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // SHIFTING
        for(int i=0; i<row; i++){
        
        int start = 0;
        int end = n-1;

            while(start < end){

                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }

        return;

    }
};
