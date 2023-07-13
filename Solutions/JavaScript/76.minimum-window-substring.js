/*
 * @lc app=leetcode id=76 lang=javascript
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var charMap = function(str) {
    let map = {};
    for (let i = 0; i < str.length; i++) {
        map[str[i]] = map[str[i]] ? map[str[i]] + 1 : 1;
    }
    return map;
}

var isContained = function(windowMap, tMap) {
    if (windowMap.length < tMap.length) {
        return false;
    }
    for (let key in tMap) {
        if (!windowMap[key] || windowMap[key] < tMap[key]) {
            return false;
        }
    }
    return true;
}

var minWindow = function(s, t) {
    let left = 0;
    let right = 0;
    let min = s.length + 1;
    let minStr = '';
    let tCharMap = charMap(t);
    let sCharMap = charMap(s);

    if (!isContained(sCharMap, tCharMap)) {
        return '';
    }
    
    let windowCharMap = {};
    while (right < s.length) {
        if (tCharMap[s[right]]) {
            windowCharMap[s[right]] = windowCharMap[s[right]] ? windowCharMap[s[right]] + 1 : 1;
        }
        while (isContained(windowCharMap, tCharMap)) {
            if (right - left + 1 < min) {
                min = right - left + 1;
                minStr = s.slice(left, right + 1);
            }
            if (tCharMap[s[left]]) {
                windowCharMap[s[left]]--;
            }
            left++;
        }
        right++;
    }

    return minStr;
};
// @lc code=end


// @after-stub-for-debug-begin
module.exports = minWindow;
// @after-stub-for-debug-end