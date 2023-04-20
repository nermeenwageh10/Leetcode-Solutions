class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        i,j=0,len(nums)-1
        c,mod=0,(10**9+7)
        nums.sort()
        while i<=j:
            if nums[i]+nums[j]<=target:
                c+=pow(2,(j-i),mod)
                i+=1
            else:
                j-=1
        return c%mod
