class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for n in num:
            while( stack and int(stack[-1]) > int(n) and k):
                stack.pop()
                k -= 1
            stack.append(str(n))
        
        # If no elements are removed, pop last elements, (increasing order)
        while(k):
            stack.pop()
            k -= 1

        # removing leading zeros
        i = 0
        while( i <len(stack) and stack[i] == "0" ):
            i += 1
            
        return ''.join(stack[i:]) if (len(stack[i:]) > 0) else "0"            
            
