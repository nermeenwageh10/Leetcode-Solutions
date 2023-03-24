class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        grid[r][c] = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int cur = 1; 
        for (int i = 0; i < 4; i++)
        {
            int nr = dx[i] + r;
            int nc = dy[i] + c; 
            if (nr >= 0 && nc >= 0 && nr < grid.size() 
            && nc < grid[0].size() && grid[nr][nc] == 1)
                cur += dfs(grid, nr, nc);
        }
        return cur;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j])
                    mx = max(mx, dfs(grid, i, j));
        return mx;
    }
};