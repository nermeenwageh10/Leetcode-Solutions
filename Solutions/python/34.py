class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def firstsearch(low,high,t):
          
            while low<=high:
                mid=(low+high)//2

                if nums[mid]==t and(( mid-1>-1 and nums[mid-1]!=t) or mid==0):
                    return mid
                elif nums[mid]>t or (nums[mid]==t and nums[mid-1]==t ):
                    high=mid-1
                elif nums[mid]<t:
                    low=mid+1
            return -1  
        def secondsearch(low,high,t):
           

            while low<=high:
                mid=(low+high)//2

                if nums[mid]==t and(( mid+1<len(nums) and nums[mid+1]!=t) or mid==len(nums)-1):
                    return mid
                elif nums[mid]>t:
                    high=mid-1
                elif nums[mid]<t or (nums[mid]==target and nums[mid+1]==t):
                    low=mid+1
            return -1
        first=firstsearch(0,len(nums)-1,target)
        second=secondsearch(0,len(nums)-1,target)
        return([first,second])
                
