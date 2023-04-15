class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
    
        max_pro , min_pro = nums[0], nums[0]
            
        #result will store the final max product
        result = max_pro
            
        for i in range(1, len(nums)):
            current = nums[i]
            
            temp_max = max( current ,  max_pro*current, current*min_pro)
            
            min_pro = min( current ,  max_pro*current, current*min_pro)
            
            max_pro = temp_max
            
            result = max(result, max_pro)
        
        return result
