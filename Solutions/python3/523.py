class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n=len(nums)
        s=0
        d={0:-1}
        for i in range(n):
            s=(s+nums[i])%k
            if s not in d:
                d[s]=i
            else:
                if i-d[s]>1:
                    return True
        return False               
