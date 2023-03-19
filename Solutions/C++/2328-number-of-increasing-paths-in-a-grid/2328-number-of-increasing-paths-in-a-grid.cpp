class Solution {
public:
    int countInc[1001][1001];
    int mod = 1e9 + 7;
    int solve(vector<vector<int>>& matrix, int r, int c){
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int& ret = countInc[r][c];
        if (~ret) return ret;
        ret = 0;
        for (int k = 0; k < 4; k++){
            int nx = dx[k] + r;
            int ny = dy[k] + c;
            if (nx < 0 || ny < 0 || nx >= matrix.size() || 
            ny >= matrix[0].size() || matrix[nx][ny] <= matrix[r][c]) continue;
            ret = (ret + 1 + solve(matrix, nx, ny) % mod) % mod;
        }
        return ret;
    }
    int countPaths(vector<vector<int>>& grid) {
        memset(countInc, -1, sizeof countInc);
        int pathsCount = 0;
        int sz = grid.size() * grid[0].size();
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                pathsCount = (pathsCount + solve(grid, i, j) % mod) % mod;
        return (pathsCount+sz)%mod;
    }
};