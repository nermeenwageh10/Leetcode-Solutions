class Solution {
public:
    bool vis[1001];
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(vis, 0, sizeof vis);
        queue<int> q;
        q.push(0);
        int visited = 1;
        vis[0] = 1;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int i = 0; i < rooms[cur].size(); i++){
                if (!vis[rooms[cur][i]]){
                    vis[rooms[cur][i]] = 1;
                    q.push(rooms[cur][i]);
                    visited++;
                }
            }
        }
        return visited == rooms.size();
    }
};