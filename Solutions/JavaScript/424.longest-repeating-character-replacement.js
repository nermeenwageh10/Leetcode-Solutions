/*
 * @lc app=leetcode id=424 lang=javascript
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */

var characterReplacement = function (s, k) {
  let max = 0;
  const stringCharSet = new Set(s);

  for (let char of stringCharSet) {
    let left = 0;
    let right = 0;
    let replaced = 0;
    while (right < s.length) {
      if (s[right] !== char) {
        replaced++;
      }
      if (replaced > k) {
        if (s[left] !== char) {
          replaced--;
        }
        left++;
      }
      max = Math.max(max, right - left + 1);
      right++;
    }
  }
  return max;
};
// @lc code=end

// @after-stub-for-debug-begin
module.exports = characterReplacement;
// @after-stub-for-debug-end
