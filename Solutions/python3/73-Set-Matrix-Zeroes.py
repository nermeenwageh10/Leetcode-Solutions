class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        d={}
        row=len(matrix)
        col=len(matrix[0])
        cols=[]
        rows=[]
        for r in range(row):
            for c in range(col):
                if matrix[r][c]==0:
                    rows.append(r)
                    cols.append(c)
        
        for r in range(row):
            for c in range(col):
                if r in rows or c in cols:
                    matrix[r][c]=0
        
        
