class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        ds, dt = {}, {}

        for i in range(len(s)):
            ds[s[i]] = 1 + ds.get(s[i], 0)
            dt[t[i]] = 1 + dt.get(t[i], 0)
        return ds == dt
        
        #Time Complexity : O(N)
        #Space Complexity : O(N)







































