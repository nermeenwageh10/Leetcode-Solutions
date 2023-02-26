    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l=0

        for r in range(len(nums)):
            if  nums[r]:
                nums[r],nums[l]=nums[l],nums[r]
                l+=1
        
