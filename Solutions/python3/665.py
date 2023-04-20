class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        cnt=0
        for i in range(1,len(nums)):
            if nums[i-1]>nums[i]:
                cnt+=1
            if i >= 2 and i+1<len(nums):
                if nums[i]<nums[i-2] and nums[i+1]<nums[i-1]:
                    return (False)
        if cnt>1:
            return(False)
        return(True)
