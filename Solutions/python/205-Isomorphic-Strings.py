class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        ds,dt={},{}

        for i in range(len(s)):

            if (s[i] in ds and ds[s[i]]!=t[i]) or  (t[i] in dt and dt[t[i]] != s[i]):
                return False 

            ds[s[i]]=t[i]
            dt[t[i]]=s[i]
        return True 
