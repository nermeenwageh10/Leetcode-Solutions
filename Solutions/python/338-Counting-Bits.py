class Solution:
    def countBits(self, n: int) -> List[int]:
        arr=[0]
        for i in range(1,n+1):
            value=bin(i).count('1')
            arr.append(value)
        return arr
