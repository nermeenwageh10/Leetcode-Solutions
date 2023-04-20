class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsub=float("-Inf")
        count=0
        for n in nums:
            count+=n
            maxsub=max(maxsub,count)
            if count<0:
                count=0
        return maxsub
