class Solution {
public:
    int dp[101][2];
    int solve(vector<int>& nums, int indx, bool takeFirstHouse){
        if (indx >= nums.size())
            return 0;
        int& ret = dp[indx][takeFirstHouse];
        if (~ret) return ret;
        ret = 0;
        if (indx == nums.size() - 1){
            if (!takeFirstHouse)
                ret = nums[indx] + solve(nums, indx + 2, takeFirstHouse);
        }else 
        {
            ret = max(solve(nums, indx + 1, takeFirstHouse), 
            nums[indx] + solve(nums, indx + 2, takeFirstHouse | (indx == 0)));
        }
        return ret;
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return solve(nums, 0, 0);
    }
};