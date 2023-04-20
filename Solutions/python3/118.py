class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        Pascal = [[0 for j in range(i)] for i in range(1, numRows+1)]
        for i in range(numRows):
            row = [1] * (i+1)
            for j in range(1, i):
                row[j] = Pascal[i-1][j-1] + Pascal[i-1][j]
            Pascal[i] = row
        return Pascal
