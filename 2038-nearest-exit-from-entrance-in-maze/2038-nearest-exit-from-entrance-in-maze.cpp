class Solution {
public:
    int BFS(vector<vector<char>>& maze, vector<int>& entrance){
        queue<pair<int,int>> qu;
        qu.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;
        int dir[5] = {-1, 0, 1, 0, -1};

        while(!qu.empty()){
            int sz = qu.size();
            for(int i = 0; i < sz; i++){
                auto [r,c] = qu.front();
                qu.pop();
                
                if((r == 0 || r == (int)maze.size()-1 ||
                    c == 0 || c == (int)maze[0].size()-1) && steps != 0){
                    return steps;
                }

                for(int d = 0; d < 4; d++){
                    int nr = r + dir[d];
                    int nc = c + dir[d+1];
                    
                    if(nr >= 0 && nr < (int)maze.size() &&
                    nc >= 0 && nc < (int)maze[0].size() &&
                    maze[nr][nc] == '.') {
                        
                        // Mark as visited in-place
                        maze[nr][nc] = '+';
                        qu.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        return BFS(maze, entrance);
    }

};