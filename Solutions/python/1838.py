class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        sum_s_w = nums[0]
        fin = 1
        i=0
        for j in range(1,n):
            sum_s_w+=nums[j]
            mx = nums[j]
            while sum_s_w+k<mx*(j-i+1):
                sum_s_w -= nums[i]
                i += 1
            fin = max(fin,j-i+1)
        return fin
