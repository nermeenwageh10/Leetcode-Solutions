class Solution {
public:
    set<string> dic;
    unordered_map<string, int> dist, dist1;
    vector<string> getAllEdges(string src){
        vector<string> edges;
        for (int pos = 0; pos < src.size(); pos++){
            for (char c = 'a'; c <= 'z'; c++){
                if (c == src[pos]) continue;
                char tempC = src[pos];
                src[pos] = c;
                if (dic.count(src))
                    edges.push_back(src);
                src[pos] = tempC;
            }
        }
        return edges;
    }
    unordered_map<string, unordered_set<string>> edgesList;
    vector<string> path;
    vector<vector<string>> allPaths;
    void solve(string src, string dst){
        if (path.size() > 1 + dist[dst]) return;
        if (src == dst){
            allPaths.push_back(path);
            return;
        }
        for (string toGo: edgesList[src]){
            if (dic.count(toGo)) continue;
            int total = dist[dst] - dist[src] - dist1[src];
            if (total != 0) continue;
            path.push_back(toGo);
            dic.insert(toGo);
            solve(toGo, dst);
            dic.erase(toGo);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); i++){
            dic.insert(wordList[i]);
        }
        
        queue<string> q;
        dist[beginWord] = 0;
        q.push(beginWord);
        edgesList.clear();
        while (q.size()){
            string cur = q.front();
            q.pop();
            int curDist = dist[cur];
            auto allEdges = getAllEdges(cur);
            for(string toGo: allEdges){
                if (dist.find(toGo) == dist.end()){
                    dist[toGo] = curDist + 1;
                    q.push(toGo);
                }
                if (dist[toGo] == curDist + 1)
                {
                    edgesList[cur].insert(toGo);
                    edgesList[toGo].insert(cur);
                }
            }
        }
        dist1[endWord] = 0;
        q.push(endWord);
        while (q.size()){
            string cur = q.front();
            q.pop();
            int curDist = dist1[cur];
            for(string toGo: edgesList[cur]){
                if (dist1.find(toGo) == dist.end()){
                    dist1[toGo] = curDist + 1;
                    q.push(toGo);
                }
            }
        }
        dic.clear();
        allPaths.clear();
        path.push_back(beginWord);
        dic.insert(beginWord);
        solve(beginWord, endWord);
        return allPaths;
    }
};