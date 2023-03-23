class Solution {
public:
    int vis[200];
    void dfs(vector<vector<int>>& isConnected, int node){
        vis[node] = 1;
        for (int i = 0; i < isConnected.size(); i++){
            if (isConnected[node][i] && !vis[i])
                dfs(isConnected, i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        for (int i = 0; i < isConnected.size(); i++){
            if (vis[i] == 0){
                cnt++;
                dfs(isConnected, i);
            }
        }
        return cnt;
    }
};