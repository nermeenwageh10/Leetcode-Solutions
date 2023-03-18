/*hint
We want to check palindrome
Solved by using reverse Array or walk from begin and end to half
*/

/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
s = s.toLowerCase(s).replace(/[^0-9a-zA-Z]/g,'');
  let n = s.length;
  for (let i = 0; i < n / 2; i++) {
    if (s[i] !== s[n - i-1]) return false;
  }
  return true;
};