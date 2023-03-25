/*
------------------- Hint ----------------------------

We want to find  the maximum amount of stored water.
Solved by using  	Two Pointers .   complexity  O(N).

*/

/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
  let l = 0,
    r = height.length - 1,
    mx = 0;

  while (l < r) {
    mx = Math.max(mx, Math.min(height[l], height[r]) * (r - l));
    if (height[l] < height[r]) l++;
    else r--;
  }

  return mx;
};
