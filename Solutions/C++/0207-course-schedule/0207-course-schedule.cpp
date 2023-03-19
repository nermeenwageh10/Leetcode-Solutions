class Solution {
public:
    vector<int> adj[2001];
    int vis[2001];
    bool dfs(int u)
    {
        vis[u] = 1;
        for (int v: adj[u])
        {
            if (vis[v] == 2) continue;
            if (vis[v] || dfs(v) == 0) return 0;
        }
        vis[u] = 2;
        return 1;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++)
            adj[i].clear(), vis[i] = 0;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        bool ok = 1;
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
                ok &= dfs(i);
        }
        return ok;
        
    }
};