class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res=[[1]]
        level=[]
        for i in range(1,numRows):
            level=[1]*(i+1)
            for l in range(len(level)):
                if l == 0 or l==len(level)-1:
                    continue
                else:
                    level[l]=res[-1][l]+res[-1][l-1]
            res.append(level)
        return res
