class Solution:
    def maxArea(self, height: List[int]) -> int:
        left,right=0,len(height)-1
        maxValue=0
        while left < right:
            value=((min(height[left],height[right])) * (right-left) )
            maxValue=max(maxValue,value)
            
            if height[left]<=height[right]:
                left+=1
            else:
                right-=1
        return(maxValue)
              
        
        #Time Complexity  : O(N)
        #Space Complexity : O(1)
