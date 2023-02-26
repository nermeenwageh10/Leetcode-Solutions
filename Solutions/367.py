class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        num=num**0.5
        while(num>=1):
            if(num%1==0):
                return(True)
            else:
                return(False)
                
