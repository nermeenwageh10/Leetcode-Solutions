/*
 * @lc app=leetcode id=153 lang=javascript
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */

var findMin = function(nums) {
    let left = 0;
    let right = nums.length - 1;
    let mid = 0;
    while (left < right) {
        mid = Math.floor((left + right) / 2);
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return nums[left];
};
// @lc code=end


// @after-stub-for-debug-begin
module.exports = findMin;
// @after-stub-for-debug-end