class Solution {
public:
    int vid, vis[6][6];
    bool found(vector<vector<char>>& board, string word, int x, int y, int p)
    {
        if (p == word.size())
            return 1;
        if (x < 0 || y < 0 || x >= board.size()||y>=board[0].size()
            ||vis[x][y] == vid|| board[x][y] != word[p])
            return 0;
        vis[x][y] = vid; 
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int k = 0; k < 4; k++)
        {
            if (found(board, word, dx[k] + x, dy[k] + y, p + 1))
                return 1; 
        }
        vis[x][y] = vid - 1;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        memset(vis, 0, sizeof vis);
        vid = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m && ++vid; j++)
                if (found(board, word, i, j, 0))
                    return 1; 
        return 0;
    }
};