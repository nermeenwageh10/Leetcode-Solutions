class Solution {
public:
    int ways[20][40000];
    int countWays(vector<int>&nums, int index, int curSum, int target){
        if (index == nums.size()){
            return (curSum == target);
        }
        int& ret = ways[index][curSum];
        if (~ret)
            return ret;
        ret = countWays(nums, index + 1, curSum + nums[index], target) + 
        countWays(nums, index + 1, curSum - nums[index], target);
        return ret;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(ways, -1, sizeof ways);
        return countWays(nums, 0, 20000, target + 20000);
    }
};