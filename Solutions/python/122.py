class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l,r=0,1
        profit=0
        while r < len(prices):
            if prices[l]<prices[r]:
                profit+=prices[r]-prices[l]
            l+=1
            r+=1
        return profit
