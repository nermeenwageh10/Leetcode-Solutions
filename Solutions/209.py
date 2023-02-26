class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n=len(nums)
        i=j=0
        s=nums[0]
        m=9999999
        while j<n and i<=j:
            if s>=target:   
                m=min(m,j-i+1)
                s-=nums[i]
                i+=1
            else:
                j+=1
                if j<n:
                    s+=nums[j]
        if m!=9999999:
            return m
        return 0
