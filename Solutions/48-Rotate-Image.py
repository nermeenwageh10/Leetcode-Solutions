class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        row = 0
        col = 0
        
        for _ in range(n//2):
            col_boundary = n - col - 1
            while col < col_boundary:
                # Swap 4 sides
                
                # Right side of the rotation
                matrix[row][col], matrix[col][n-1-row] = matrix[col][n-1-row], matrix[row][col]
                
                # Bottom side of the rotation
                matrix[row][col], matrix[n-1-row][n-1-col] = matrix[n-1-row][n-1-col], matrix[row][col]
                
                # Left side of the rotation
                matrix[row][col], matrix[n-1-col][row]  = matrix[n-1-col][row], matrix[row][col]
                
                col += 1
            
            row += 1
            col = row
