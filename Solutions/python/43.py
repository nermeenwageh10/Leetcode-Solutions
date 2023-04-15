class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        dic={
            '1':1,
            '2':2,
            '3':3,
            '4':4,
            '5':5,
            '6':6,
            '7':7,
            '8':8,
            '9':9,
            '0':0
        }
        h=list(num1)
        l=list(num2)
        s=len(num1)-1
        s1=len(l)-1
        k=0
        k1=0
        p=0
        p1=0
        while h:
            r=h.pop(s)
            p1+=(10**k)*dic[r]
            k+=1
            s-=1
        while l:
            r=l.pop(s1)
            p+=(10**k1)*dic[r]
            k1+=1
            s1-=1
        return str((p1*p))
        
