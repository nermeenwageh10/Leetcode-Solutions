class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        ans = float('inf')
        start = 1
        end = max(piles) + 1
        while start <= end:
            mid = (start + end)//2
            hour = 0
            for i in piles:
                if i%mid==0: 
                    hour += i//mid
                else: 
                    hour += i//mid + 1
            print(hour)
            if hour > h: 
                start = mid + 1
            else: 
                ans = min(mid, ans)
                end = mid - 1
        return ans
