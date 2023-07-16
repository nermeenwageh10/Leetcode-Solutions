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

//another solution without replace
// var isPalindrome = function(s) {
//   let left = 0;
//   let right = s.length - 1;
//   while (left < right) {
//       if (!s[left].match(/[a-zA-Z0-9]/)) {
//           left++;
//           continue;
//       }
//       if (!s[right].match(/[a-zA-Z0-9]/)) {
//           right--;
//           continue;
//       }
//       if (s[left].toLowerCase() !== s[right].toLowerCase()) {
//           return false;
//       }
//       left++;
//       right--;
//   }
//   return true;
  
// };