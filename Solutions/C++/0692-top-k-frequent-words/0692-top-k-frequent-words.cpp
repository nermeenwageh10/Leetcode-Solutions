class Solution {
public:
    unordered_map<string, int> frq;
    struct cmp{
      unordered_map<string, int>& frq;
      bool operator()(const string& a, const string& b){
          if (frq[a] != frq[b])
                return frq[a] > frq[b];
            return a < b;
      }  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        frq = unordered_map<string, int>();
        for (int i = 0; i < words.size(); i++)
            frq[words[i]]++;
        cmp comp{frq};
        priority_queue<string, vector<string>, cmp> pq(comp);
        for (auto i: frq){
            pq.push(i.first);
            if (pq.size() > k)
                pq.pop();
        }
        for (int i = k-1; i >= 0; i--)
        {
            words[i] = pq.top();
            pq.pop();
        }
        words.erase(words.begin() + k, words.end());
        return words;
        
    }
};