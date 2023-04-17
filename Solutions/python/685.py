class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows,cols=len(grid),len(grid[0])
        visit=set()
        def dfs(i,j):
            if i <0 or i==rows or j <0 or j==cols or grid[i][j]==0 or (i,j) in visit:
                return 0 
            visit.add((i,j))
            return(1+ dfs(i+1,j) + dfs(i-1,j) + dfs(i,j+1) + dfs(i,j-1))
        area=0
        for m in range(rows):
            for n in range(cols):
                area=max(area,dfs(m,n))
        return area
        
