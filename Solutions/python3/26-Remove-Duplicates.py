class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        end =len(nums)
        i=1
        while True:
            if(i==end):
                break
            if(nums[i]==nums[i-1]):
                nums.remove(nums[i])
                i-=1
                end=len(nums)
            i+=1
        return(len(nums))
            
            
     
