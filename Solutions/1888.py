class Solution:
    def minFlips(self, s: str) -> int:
        mod_s = s
        mod_s += s
        tgt1 = []
        tgt2 = []
        flag = 0
        for i in range(len(mod_s)):
            tgt1.append(f'{flag}')
            tgt2.append(f'{int(not(flag))}')
            flag = int(not(flag))
        res = [0,0]
        for k in range(len(s)):
            if s[k]!=tgt1[k]:
                res[0]+=1
            if s[k]!=tgt2[k]:
                res[1]+=1
        l = 1
        r = len(s)
        ans = min(res)
        while r<len(mod_s):
            if mod_s[r]!=tgt1[r]:
                res[0]+=1
            if mod_s[l-1]!=tgt1[l-1]:
                res[0]-=1
            if mod_s[r]!=tgt2[r]:
                res[1]+=1
            if mod_s[l-1]!=tgt2[l-1]:
                res[1]-=1
            l+=1
            r+=1
            ans = min(ans,min(res))
        return ans



            
