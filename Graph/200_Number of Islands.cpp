// 200. Number of Islands

bool valid(int i, int j, vector<vector<char>>& grid){

    return i>=0 && i<grid.size() && j>=0 && j<grid[0].size();
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};
        
        int r = grid.size();
        int c = grid[0].size();

        int count = 0;
        queue<pair<int,int>>q;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                if(grid[i][j] == '1'){
                    count++;
                    q.push({i,j});
                    grid[i][j] = '0';

                    while(!q.empty()){

                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();

                        for(int k=0; k<4; k++){

                            if(valid(new_i + row[k], new_j + col[k], grid) && (grid[new_i + row[k]][new_j + col[k]] == '1')){

                                grid[new_i + row[k]][new_j + col[k]] = '0';
                                q.push({new_i + row[k], new_j + col[k]});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};
