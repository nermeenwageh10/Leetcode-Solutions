class Solution {
public:
    int mn;
    vector<bool> vis;
    void dfs(vector<vector<int>> &adj, int node){
        vis[node] = 1;
        for (int i = 0; i < adj[node].size(); i+=2){
            int v = adj[node][i];
            int c = adj[node][i+1];
            mn = min(mn, c);
            if (vis[v]) continue;
            dfs(adj, v);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vis = vector<bool>(n, 0);
        mn = 1e9;
        for (int i = 0; i < roads.size(); i++){
            adj[roads[i][0]-1].push_back(roads[i][1]-1);
            adj[roads[i][0]-1].push_back(roads[i][2]);
            adj[roads[i][1]-1].push_back(roads[i][0]-1);
            adj[roads[i][1]-1].push_back(roads[i][2]);
        }
        dfs(adj, n-1);        
        return mn;
    }
};