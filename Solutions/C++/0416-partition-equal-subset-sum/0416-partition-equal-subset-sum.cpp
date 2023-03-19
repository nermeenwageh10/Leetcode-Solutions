class Solution {
public:
    int dp[201][10001];
    int solve(vector<int>& nums, int i, int rem){
        if (rem == 0) return 1;
        if (i == nums.size() || rem < 0) return 0;
        int &ret = dp[i][rem];
        if (~ret) return ret;
        ret = max(solve(nums, i + 1, rem), solve(nums, i + 1, rem - nums[i]));
        return ret;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum & 1) return 0;
        sum /= 2;
        memset(dp, -1, sizeof dp);
        return solve(nums, 0, sum);    
    }
};