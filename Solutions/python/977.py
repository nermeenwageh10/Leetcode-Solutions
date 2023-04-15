class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            nums[i]=pow(nums[i],2)
        return(sorted(nums))
            
