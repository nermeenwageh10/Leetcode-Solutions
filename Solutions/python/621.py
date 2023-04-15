import heapq
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        ans, hashMap, heap = 0, Counter(tasks), []
    
        for key in hashMap:
            heappush(heap, -hashMap[key])
            
            
        while len(heap):
            
            tt, arr = 0, []
            for i in range(n + 1):
                if len(heap):
                    arr.append(-heappop(heap) - 1)
                    tt += 1
                    
            for i in arr:
                if i > 0:
                    heappush(heap, -i)
           
            if not len(heap):
                ans += tt
            else:
                ans += (n + 1)
        return ans
