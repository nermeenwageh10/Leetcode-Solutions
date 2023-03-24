class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int good = 0;
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++){
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    good++;
            }
        if (good == 0) return 0;
        int t = 0;
        while (good && !q.empty()){
            int sz = q.size();
            while (sz--)
            {
                auto cur = q.front();
                q.pop();
                int dx[] = {1, -1, 0, 0};
                int dy[] = {0, 0, 1, -1};
                for (int i = 0; i < 4; i++){
                    int nr = cur[0] + dx[i];
                    int nc = cur[1] + dy[i];
                    if (nr < 0 || nc < 0 || nr >= r 
                        || nc >= c || grid[nr][nc] != 1) continue;
                    good--;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
            t++;
        }
        return (good == 0? t: -1);
    }
};