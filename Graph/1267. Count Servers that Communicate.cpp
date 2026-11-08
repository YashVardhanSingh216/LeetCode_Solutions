// 1267. Count Servers that Communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> rowServer(row, 0);
        vector<int> colServer(col, 0);

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 1) {
                    rowServer[i]++;
                    colServer[j]++;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 1 && (rowServer[i] > 1 || colServer[j] > 1)) {
                    count++;
                }
            }
        }
        return count;
    }
};
