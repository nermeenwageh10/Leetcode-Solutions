class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        cache = {}
        
        def dp(i, curr):
            if (i, curr) in cache:
                return cache[(i, curr)]
            if i == n:
                return int(curr == target)
            
            cache[(i,curr)] = dp(i+1, curr + nums[i]) + dp(i+1, curr - nums[i])
            return cache[(i, curr)]
    
        return dp(0, 0)
