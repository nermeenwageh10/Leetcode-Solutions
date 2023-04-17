class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total=sum(nums) #O(n)
        left=0 

        for i in range(len(nums)) :
            
            right=total-nums[i]-left
            if left==right:
                return i 
            left+=nums[i]
        return -1

       
        #O(N)
