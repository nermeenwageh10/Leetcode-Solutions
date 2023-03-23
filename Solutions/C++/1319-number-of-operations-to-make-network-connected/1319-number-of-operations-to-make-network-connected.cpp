class Solution {
public:
    vector<int> adj[100001];
    int vis[100001];
    void dfs(int u){
        vis[u] = 1;
        for (int v: adj[u]){
            if (vis[v] == 0)
                dfs(v);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        for (int i = 0; i < n; i++) adj[i].clear();
        if (connections.size() < n - 1) return -1;
        for (int i = 0; i < connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int ret = -1;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                dfs(i);
                ret++;
            }
        }
        return ret;
    }
};