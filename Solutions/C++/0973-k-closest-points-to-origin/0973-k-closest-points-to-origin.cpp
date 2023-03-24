class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        auto GetDist = [&](int index){
            int sum = 0;
            for (int i = 0; i < 2; i++)
                sum += points[index][i] * points[index][i];
            return sum; 
        };
        for (int i = 0; i < points.size(); i++){
            pq.push({GetDist(i),i});
            while (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ret;
        while (pq.size() > 0){
            int index = pq.top()[1];
            ret.push_back(points[index]);
            pq.pop();
        }
        return ret;

    }
};