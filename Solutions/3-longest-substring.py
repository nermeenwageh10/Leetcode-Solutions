class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        HashSet = set()
        l = 0
        res = 0

        for r in range(len(s)):
            while s[r] in HashSet:
                HashSet.remove(s[l])
                l += 1
            HashSet.add(s[r])
            res = max(res, r - l + 1)
        return res
        
        #Time Complexity: O(N)
        #Space Complexity: O(N)
