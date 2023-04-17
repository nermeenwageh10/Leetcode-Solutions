class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = list()
        while len(matrix) > 0:
            try:
                result += matrix.pop(0) #remove the first nested list (top row)
                result += [x.pop(-1) for x in matrix] #remove every last element of the lists (right row)															
                result += matrix.pop(-1)[::-1] #remove last nested list in reverse order (bottom row)
                result += [x.pop(0) for x in matrix][::-1] #remove every last element of the lists (left row)
            except:
                break #if at any moment the matrix is empty, break the loop and return the result array
        return result
