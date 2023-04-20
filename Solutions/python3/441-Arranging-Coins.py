class Solution:
    def arrangeCoins(self, n: int) -> int:
        l = 1
        h = n
        while l<=h:
            mid = l + (h-l)//2
            temp = int(mid*(mid+1)/2)
            if temp == n:
                return mid
            if temp < n:
                l = mid + 1
            else:
                h = mid - 1
        return h
            
