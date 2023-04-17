class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows, cols = len(matrix), len(matrix[0])

        low,high=0,rows-1
        
        while low<=high:
            row=(low+high)//2
            
            if target > matrix[row][-1]:
                low=row+1
            elif target < matrix[row][0]:
                high=row-1
            else :
                 break
        if high <low :
            return False
        low,high=0,cols-1
        
        while low <= high :
            mid=(low+high)//2
            
            if matrix[row][mid]==target:
                return True
            elif matrix[row][mid] > target:
                high=mid-1
            elif matrix[row][mid] < target:
                low=mid+1
        return False
