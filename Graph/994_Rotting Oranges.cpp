// 994. Rotting Oranges

bool valid(int i, int  j, vector<vector<int>>& grid){

    return i>=0 && i<grid.size() && j>=0 && j<grid[0].size();
}
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};
        
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int,int>>q;
        int fresh = 0;

        for(int i=0;i<r;i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 2) q.push({i,j});

                else if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int timer = 0;
        while(!q.empty()){
            timer++;
            int curr_org = q.size();

            while(curr_org--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(int k=0; k<4; k++){

                    if(valid(i + row[k], j + col[k], grid) && grid[i+row[k]][j+col[k]] == 1){
                        grid[i+row[k]][j+col[k]] = 2;
                        q.push({i+row[k],j+col[k]});
                        fresh--;
                    }
                }
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return (fresh == 0) ? timer-1 : -1;



    }
};
