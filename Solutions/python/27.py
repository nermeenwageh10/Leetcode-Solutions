def removeElement(self, nums: List[int], val: int) -> int:
        while val in nums:
            nums.remove(val)
