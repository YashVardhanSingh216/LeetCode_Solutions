// 1254. Number of Closed Islands

bool valid(int i, int j, vector<vector<int>>& grid) {

    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};

        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;
        int count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (grid[i][j] == 0) {
                    q.push({i, j});
                    grid[i][j] = 1;
                    bool closed = true;

                    while (!q.empty()) {

                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        if((new_i == 0 || new_i == r - 1) || (new_j == 0 || new_j == c - 1))
                        closed = false;

                        for (int k = 0; k < 4; k++) {

                            if (valid(new_i + row[k], new_j + col[k], grid) &&
                                grid[new_i + row[k]][new_j + col[k]] == 0) {
                                grid[new_i + row[k]][new_j + col[k]] = 1;
                                q.push({new_i + row[k], new_j + col[k]});
                            }
                        }
                    }

                    if(closed)
                    count++;
                }
            }
        }
        return count;
    }
};
