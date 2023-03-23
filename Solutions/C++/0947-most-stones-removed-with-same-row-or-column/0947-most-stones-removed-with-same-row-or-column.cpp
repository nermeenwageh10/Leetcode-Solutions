class Solution {
public:
    bool vis[1001];
    int dfs(vector<vector<int>>& stones, int point){
        vis[point] = 1;
        int removed = 0;
        for (int i = 0; i < stones.size(); i++){
            if (vis[i]) continue;
            if (stones[i][0] == stones[point][0] || stones[i][1] == stones[point][1]){
                removed += 1 + dfs(stones, i);
            }
        }
        return removed;
    }
    int removeStones(vector<vector<int>>& stones) {
        memset(vis, 0, sizeof vis);
        int ans = 0;
        for (int i = 0; i < stones.size(); i++){
            if (!vis[i])
                ans += dfs(stones, i);
        }
        return ans;
    }
};