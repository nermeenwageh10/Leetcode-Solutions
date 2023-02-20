class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binarySearch(left, right, pivot) -> int:
            while left <= right:
                mid = left + (right - left) // 2
                if nums[(mid + pivot) % len(nums)] > target:
                    right = mid - 1
                elif nums[(mid + pivot) % len(nums)] < target:
                    left = mid + 1
                else:
                    return (mid + pivot) % len(nums)
            return -1
        pivot = nums.index(min(nums))
        left, right = 0, len(nums) - 1
        index = binarySearch(left, right, pivot)
        return index
      
      
      #Time:O(N)
      #Space:O(1)
