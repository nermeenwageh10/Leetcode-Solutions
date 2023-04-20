import heapq
class Solution:
    def reorganizeString(self, s: str) -> str:
        res=""
        d={}
        heap=[]
        for c in s:
            d[c]=1+d.get(c,0)
        for c in d:
            heapq.heappush(heap,(-d[c],c))

        while heap:
            arr=[]
            for ch in  range(2):
                if len(heap):
                    c,s=heapq.heappop(heap)
                    c*=-1
                    res+=s
                    c-=1
                    if c>0:
                        arr.append([-c,s])
            for c,s in arr:
                heapq.heappush(heap,(c,s))
        if len(res)>2 and res[-1]==res[-2]:
            return ("")
        return(res)
                

     
