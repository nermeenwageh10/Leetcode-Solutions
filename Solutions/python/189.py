class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        for i in range(k):
            temp=nums[-1]
            nums.pop(len(nums)-1)
            nums.insert(0,temp)
        return(nums)
