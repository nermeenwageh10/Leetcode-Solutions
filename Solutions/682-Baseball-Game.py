class Solution:
    def calPoints(self, ops: List[str]) -> int:
        stack=[]
        for i in ops:
            if i=='+' and len(stack)>1:
                num1=stack[-1]
                num2=stack[-2]
                stack.append((num1)+(num2))
            elif i=="C" and stack:
                stack.pop()
            elif i=='D' and stack:
                num1=stack[-1]
                stack.append((num1)*2)
            else:
                stack.append(int(i))
        return(sum(stack))
