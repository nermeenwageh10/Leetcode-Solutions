class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        k++;
        while (q.size() && k){
            int size = q.size();
            vector<int> oldDistance = dist;
            while (size--){
                int cur = q.front();
                q.pop();
                for (int i = 0; i < flights.size(); i++){
                    if (flights[i][0] != cur) continue;
                    int v = flights[i][1];
                    int c = flights[i][2];
                    if (dist[v] == -1 || dist[v] > oldDistance[cur] + c){
                        dist[v] = oldDistance[cur] + c;
                        q.push(v);
                    }
                }
            }
            k--;
        }
        return dist[dst];
    }
};