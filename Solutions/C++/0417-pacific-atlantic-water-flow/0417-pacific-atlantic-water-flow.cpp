class Solution {
public:
    int R, C;
    static constexpr const int dx[] = {1, -1, 0, 0};
    static constexpr const int dy[] = {0, 0, 1, -1};
    
    int vis[205][205];
    int cellState[205][205];
    int canReach(vector<vector<int>>& heights, int r, int c){
        if (r == 0 || c == 0) cellState[r][c] |= (1<<0);
        if (c == C-1 || r == R-1) cellState[r][c] |= (1<<1);
        if (vis[r][c]) {
            for (int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nc < 0 || nr < 0 || nc >= C || nr >= R || 
                heights[r][c] < heights[nr][nc]) continue;
                cellState[r][c] |= cellState[nr][nc];
            }
            return cellState[r][c];
        }
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nc < 0 || nr < 0 || nc >= C || nr >= R || 
            heights[r][c] < heights[nr][nc]) continue;
            cellState[r][c] |= canReach(heights, nr, nc);
        }
        return cellState[r][c];
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        R = heights.size(), C = heights[0].size();
       
        memset(cellState, 0, sizeof cellState);
        memset(vis, 0, sizeof vis);
    
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                canReach(heights, i, j);
            }
        }
        
        vector<vector<int>> ret;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (cellState[i][j] == 3)
                    ret.push_back({i, j});
        return ret;
    }
};