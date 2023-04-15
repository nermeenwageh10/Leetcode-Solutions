class MinStack:
    def __init__(self):
        self.minStack = []
    def push(self, val: int) -> None:
        self.minStack.append(val)

    def pop(self) -> None:
        if self.minStack:
            self.minStack.pop()

    def top(self) -> int:
        return(self.minStack[-1])

    def getMin(self) -> int:
        return(min(self.minStack))
# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
