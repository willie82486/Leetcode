class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int col = 0; col < grid[0].size(); col++){
            for(int row = 1; row < grid.size(); row++){
                while(grid[row][col] <= grid[row - 1][col]){
                    grid[row][col] += 1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};