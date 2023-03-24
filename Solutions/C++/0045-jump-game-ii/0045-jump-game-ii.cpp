class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> mnJumps(nums.size(), (int)1e9);
        mnJumps[nums.size()-1] = 0;
        for (int i = nums.size()-2; i >= 0; i--){
            for (int j = min((int)nums.size()-1, nums[i] + i); j > i; j--){
                mnJumps[i] = min(mnJumps[i], 1 + mnJumps[j]);
            }
        }
        return mnJumps[0];
    }
};