class Solution:
    def maxProduct(self, s: str) -> int:
        subs = []
        n = len(s)
        def dfs(curr, ind, inds):
            if ind == n:
                if curr == curr[::-1]:
                    subs.append((curr, inds))
                return
            dfs(curr+s[ind], ind+1, inds|{ind})
            dfs(curr, ind+1, inds)
        
        dfs('', 0, set())
        
        res = 0
        n = len(subs)
        for i in range(n):
            s1, i1 = subs[i]
            for j in range(i+1, n):
                s2, i2 = subs[j]
                if len(i1 & i2) == 0:
                    res = max(res, len(s1)*len(s2))
        return res
