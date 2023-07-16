// Author: Ahmed Gamal

// for this problem, we will use the sliding window technique
// we will use two pointers, one for the left side of the window and the other for the right side
// we will use a map to store the frequency of each character in the window
// once we find a duplicate character, we will move the left pointer to the right until we remove the duplicate character
// we will keep track of the maximum length of the window and return it at the end

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    // freq: map to store the frequency of each character in the window
    const freq = new Map();

    // l: left pointer, r: right pointer
    // ans: maximum length of the window
    let l = 0, ans = 0;

    // loop over the string
    for(let r = 0; r < s.length; r++) {
        // if the character is not in the map, add it with frequency 0
        if(!freq.has(s[r])) {
            freq.set(s[r], 0);
        }

        // increment the frequency of the character
        freq.set(s[r], freq.get(s[r]) + 1);
        
        // if the frequency of the character is greater than 1, move the left pointer to the right until we remove the duplicate character
        while(freq.get(s[r]) > 1) {
            // decrement the frequency of the character
            freq.set(s[l], freq.get(s[l]) - 1);
            // move the left pointer to the right
            l++;
        }

        // update the maximum length of the window
        ans = Math.max(ans, r - l + 1);
    }

    // return the maximum length of the window
    return ans;
};

// Solution 2: without HashTable
// var lengthOfLongestSubstring = function(s) {
//     let left = 0;
//     let right = 0;
//     let max = 0;
//     while (right < s.length) {
//         if(s.slice(left, right).includes(s[right])) {
//             left++;
//         } else {
//             max = Math.max(max, right - left + 1);
//             right++;
//         }
//     }
//     return max;    
// };