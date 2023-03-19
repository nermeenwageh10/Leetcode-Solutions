class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int delta = 1e4;
        vector<int> frq(2 * delta + 2, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            frq[nums[i] + delta]++;
        }
        priority_queue<vector<int>> pq;
        for (int i = 0; i <= 2 * delta; i++){
            if (frq[i] > 0){
                pq.push({-frq[i], i - delta});
            }
            while (pq.size() > k){
                pq.pop();
            }
        }
        vector<int> topK;
        while (pq.size()){
            topK.push_back(pq.top()[1]);
            pq.pop();
        }
        return topK;
    }
};
// time N Log(K)