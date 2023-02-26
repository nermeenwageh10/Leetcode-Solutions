class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1)>len(s2):
            return False
        d1={}
        d2={}
        for i in range(len(s1)):
            d1[s1[i]]= d1.get(s1[i],0)+1
            d2[s2[i]]= d2.get(s2[i],0)+1
        l=0
        if len(s1)==len(s2):
            return d1==d2
        for r in range(len(s1),len(s2)):
            if d1==d2:
                return True
            d2[s2[l]]-=1
            if d2[s2[l]] == 0:
                del d2[s2[l]] 
            l+=1
            d2[s2[r]] = 1+d2.get(s2[r],0)
        if d1==d2:
            return True
        return False
            
