class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        maximum = 0
        setNm = set(nums) 
        for n in nums:
            if n-1 not in setNm:
                i = 0
                while n+i in setNm:
                    setNm.remove(n+i)
                    i+=1
                maximum = max(maximum,i)
        return maximum
        
        #Time Complexity  : O(N)
        #Space Complexity : O(N)
