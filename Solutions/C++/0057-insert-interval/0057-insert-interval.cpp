class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> stk;
        stk.push(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > stk.top()[1])
                stk.push(intervals[i]);
            else 
                stk.top()[1] = max(stk.top()[1], intervals[i][1]);
        }
        intervals.clear();
        while(!stk.empty())
            intervals.push_back(stk.top()), stk.pop();
        reverse(intervals.begin(), intervals.end());
        return intervals;
    }
};