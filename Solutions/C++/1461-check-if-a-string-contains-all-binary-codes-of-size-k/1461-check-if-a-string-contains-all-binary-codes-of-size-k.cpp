class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return 0;
        unordered_set<int> masks;
        int hashValue = 0;
        for (int i = 0; i < k-1; i++){
            hashValue = (hashValue << 1) | (s[i] == '1');
        }
        for (int i = 0, j = k-1; j < s.size(); i++, j++){
            hashValue = (hashValue << 1) | (s[j] == '1');
            hashValue &= ((1<<k) - 1);
            masks.insert(hashValue);
            if (masks.size() == (1<<k)) return 1;
        }
        return 0;
    }
};