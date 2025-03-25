class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    int BFS(vector<vector<int>>& grid, int m, int n){
        int minute = -1;
        queue<vector<int>> will_rotten;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = true;
                    will_rotten.push({i, j});
                    // cout << "Minute: " << minute + 1 << " Row: " << i << " Col: " << j << endl;
                }
            }
        }
        if(will_rotten.empty()) return 0;
        while(!will_rotten.empty()){
            minute++;
            int size = will_rotten.size();
            for(int i = 0; i < size; i++){
                int curLocationRow = will_rotten.front()[0];
                int curLocationCol = will_rotten.front()[1];
                will_rotten.pop();
                grid[curLocationRow][curLocationCol] = 2;
                for(int d = 0; d < 4; d++){
                    if((curLocationRow + dir[d] < m) && (curLocationRow + dir[d] >= 0)
                        && (curLocationCol + dir[d+1] < n && curLocationCol + dir[d+1] >= 0) 
                        && !visited[curLocationRow + dir[d]][curLocationCol + dir[d+1]]
                        && grid[curLocationRow + dir[d]][curLocationCol + dir[d+1]] == 1){
                            will_rotten.push({curLocationRow + dir[d], curLocationCol + dir[d+1]});
                            visited[curLocationRow + dir[d]][curLocationCol + dir[d+1]] = true;
                            // cout << "Minute: " << minute + 1 << " Row: " << curLocationRow + dir[d] << " Col: " << curLocationCol + dir[d+1] << endl;
                        }
                }
            }
        }
        return minute;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minute = BFS(grid, m, n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return minute;
    }
};