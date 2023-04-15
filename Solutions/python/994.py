class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row,col=len(grid),len(grid[0])
        der = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        visited,steps=set(),0
        q=collections.deque()
        
        for m in range(row):
            for n in range(col):
                if grid[m][n]==1:
                    visited.add((m,n))
                if grid[m][n]==2:
                    q.append((m,n))
                    
        while visited  and q:
            qlen=len(q)

            for i in range(qlen):

                r,c=q.popleft()
                for dr,dc in der:
                    x,y=r+dr,c+dc
                    if  (x in range(row) and y in range(col) and (x,y) in visited):
                        grid[x][y]=2
                        q.append((x,y))
                        visited.remove((x,y))
            steps+=1
        if not visited :
            return steps
        else:
            return -1
