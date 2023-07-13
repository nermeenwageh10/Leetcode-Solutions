/*
 * @lc app=leetcode id=33 lang=javascript
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var binarySearch = function(nums, target, start, end) {
    if (start > end) return -1;
    var mid = Math.floor((start + end) / 2);
    if (nums[mid] === target) return mid;
    if (nums[mid] > target) return binarySearch(nums, target, start, mid - 1);
    return binarySearch(nums, target, mid + 1, end);
}
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
    return left;
};

var search = function(nums, target) {
    let minElement = findMin(nums);
    let leftBinarySearch = binarySearch(nums, target, 0, minElement - 1);
    let rightBinarySearch = binarySearch(nums, target, minElement, nums.length - 1);
    if (leftBinarySearch !== -1) return leftBinarySearch;
    if (rightBinarySearch !== -1) return rightBinarySearch;
    return -1;
};
// @lc code=end

