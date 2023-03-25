class Solution {
public:
    vector<vector<int>> adj[500001];
    int vis[500001];
    int dfs(int node, int par){
        int flip = 0;
        vis[node] = 1;
        for (auto i: adj[node]){
            int v = i[0];
            int c = i[1];
            if (v == par) continue;
            if (!vis[v]){
                flip += c + dfs(v, node);
            }
        }
        return flip;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            adj[i].clear();
        }
        for (int i = 0; i < connections.size(); i++){
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
            
        }
        return dfs(0, 0);
    }
};