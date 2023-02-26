import heapq
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        heap=[]
        for num in arr :
            heapq.heappush(heap,[num,abs(num-x)])
        heap.sort(key = lambda x: x[1])
        result=heap[:k]
        ans=[]
        for num in result:
            ans.append(num[0])
        return(sorted(ans))
