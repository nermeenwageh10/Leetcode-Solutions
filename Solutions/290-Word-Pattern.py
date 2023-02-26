class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        dp,ds={},{}
        s=s.split()
        if len(pattern)!=len(s):
            return False
        for i in range(len(pattern)) :
            if pattern[i] in dp and dp[pattern[i]] != s[i] or s[i] in ds and ds[s[i]]!=pattern[i]:
                return False
            dp[pattern[i]]=s[i]
            ds[s[i]]=pattern[i]
        return True
            
        
