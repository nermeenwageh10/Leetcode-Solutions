class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for(int i = 0; i < intervals.size(); i++)
        {
            if (ret.empty() || intervals[i][0] > ret.back()[1])
                ret.push_back(intervals[i]);
            else 
                ret.back()[1] = max(ret.back()[1], intervals[i][1]); 
        }
        return ret;
    }
};