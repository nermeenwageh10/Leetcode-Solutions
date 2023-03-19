class Solution {
public:
    vector<int> current;
    vector<vector<int>> ret; 
    void take_or_leave(vector<int>& candidates, int target, int msk, int cnt, int idx)
    {
        if (target == 0)
        {
            ret.push_back(current);
            return;
        }
        if (target < 0 || idx >= candidates.size())return; 
        current.push_back(candidates[idx]);
        take_or_leave(candidates, target - candidates[idx], msk ^ (1<<(idx)), cnt+1, idx); 
        current.pop_back();
        take_or_leave(candidates, target, msk, cnt, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     ret.clear(); 
     current.clear();
     take_or_leave(candidates, target, 0, 0, 0);   
     return ret; 
    }
};