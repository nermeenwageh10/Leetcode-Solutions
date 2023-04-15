class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        jumps = 0
        maxReach = 0
        curReach = 0
        for i in range(n - 1):
            maxReach = max(maxReach, i + nums[i])
            if i == curReach:
                jumps += 1
                curReach = maxReach
            if curReach >= n - 1:
                return jumps
            if i >= maxReach:
                return 0
        return jumps
