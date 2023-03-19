class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [](vector<int>&a, vector<int>&b)
             {
                return a[0] < b[0]; 
             });
        int ans = 0;
        int r = -1e9;
        for(int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= r)
            {
                r = intervals[i][1];
            }else 
            {
                ans++; 
                r = min(r, intervals[i][1]);
            }
        }
        return ans;
    }
};