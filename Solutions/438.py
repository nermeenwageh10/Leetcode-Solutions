class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        dp=Counter(p)
        ds={}

        l,r=0,0
        ans=[]

        while r <len(s):
            ds[s[r]]=1+ds.get(s[r],0)
            if ds==dp:
                ans.append(l)
            if r-l+1 ==len(p):
                ds[s[l]]-=1
                if ds[s[l]]==0:
                    del ds[s[l]]
                l+=1
            r+=1
        return ans
