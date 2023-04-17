class NumArray:

    def __init__(self, nums: List[int]):
        self.nums=[0]+list(accumulate(nums))
        print(self.nums)

    def sumRange(self, left: int, right: int) -> int:
        return self.nums[right+1]-self.nums[left]

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
