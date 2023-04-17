class Solution(object):
    def gridGame(self, grid):
        
        top, bottom = grid
        top_sum = sum(top)
        bottom_sum = 0
        res = float('inf')
        
        for i in range(len(top)):
            top_sum -= top[i]
            res = min(res, max(top_sum, bottom_sum))
            bottom_sum += bottom[i]
            
        return res
