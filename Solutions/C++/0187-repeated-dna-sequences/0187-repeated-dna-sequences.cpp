class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> seen;
        vector<string> ret;
        for(int i = 0; i + 10 <= s.size(); i++)
        {
            string cur = s.substr(i, 10);
            if (++seen[cur] == 2)
                ret.push_back(cur);
        }
        return ret;
    }
};