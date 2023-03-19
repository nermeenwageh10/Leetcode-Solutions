class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        grid[r][c] = '0';
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int nr = dx[i] + r;
            int nc = dy[i] + c; 
            if (nr >= 0 && nc >= 0 && nr < grid.size() 
                && nc < grid[0].size() && grid[nr][nc] == '1')
                dfs(grid, nr, nc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == '1')
                {
                    numberOfIslands++;
                    dfs(grid, i, j);
                }
        return numberOfIslands;
    }
};