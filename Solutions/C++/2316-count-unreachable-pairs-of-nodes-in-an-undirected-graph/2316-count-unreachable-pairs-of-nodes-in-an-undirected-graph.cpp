class Solution {
public:
    vector<int> adj[100000];
    int vis[100000];
    int dfs(int u){
        vis[u] = 1;
        int cnt = 1;
        for (int v: adj[u]){
            if (vis[v]) continue;
            cnt += dfs(v);
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i++){
            vis[i] = 0;
            adj[i].clear();
        }
        for (int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> comLen;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                comLen.push_back(dfs(i));
            }
        }
        long long cnt = 0;
        for (int i = 0; i < comLen.size(); i++){
            cnt += 1LL * comLen[i] * (n - comLen[i]);
        }
        return cnt >> 1LL;
    }
};