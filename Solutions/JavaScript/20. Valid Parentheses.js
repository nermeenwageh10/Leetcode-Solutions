/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [] //uses only push and pop (FILO)
    let pairs = {
            '(':')', 
            '[':']',
            '{':'}'
        }
    for(let i = 0; i < s.length; i++){
        if (s[i] in pairs){
            stack.push(s[i])
        }
        else if (stack.length == 0 || s[i] != pairs[stack.pop()]){
            return false
        }
        }
        return stack.length == 0
}