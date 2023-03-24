class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n);
        vector<int> nodes;
        for (int i = 0; i < edges.size(); i++){
            inDegree[edges[i][1]]++;
        }
        for (int i = 0; i < n; i++){
            if (inDegree[i] == 0){
                nodes.push_back(i);
            }
        }
        if (nodes.size() == 0)
            nodes.push_back(0);
        return nodes;
    }
};