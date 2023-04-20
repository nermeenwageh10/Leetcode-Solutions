class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap=[]
        for x,y in points:
            ans=(abs(x - 0) ** 2) + (abs(y - 0) ** 2)
            heap.append([ans,x,y])
        heapq.heapify(heap)
        res=[]
        for i in range(k):
            dist, x, y = heapq.heappop(heap)
            res.append([x, y])
        return res
