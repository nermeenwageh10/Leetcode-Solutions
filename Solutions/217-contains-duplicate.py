class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashSet=set()
        
        for n in nums :
            if n in hashSet:
                return True
            hashSet.add(n)
        return False
      
    #Time complexity : O(N)
    #Space complexity : O(N)
