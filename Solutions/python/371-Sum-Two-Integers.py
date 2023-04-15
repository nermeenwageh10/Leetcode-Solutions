class Solution:
    def getSum(self, a: int, b: int) -> int:
        if a == 0 : 
            return b
        
        if b == 0:
            return a
        
        
        carry = 0
        
        while b != 0 :
            carry = (a & b) << 1
            
            a = a ^ b
            b = carry
        
        return a
    
