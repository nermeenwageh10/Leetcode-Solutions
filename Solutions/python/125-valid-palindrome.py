#Solution 1

class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not self.alphanum(s[l]):
                l += 1
            while l < r and not self.alphanum(s[r]):
                r -= 1
            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True

    def alphanum(self, c):
        return (
            ord("A") <= ord(c) <= ord("Z")
            or ord("a") <= ord(c) <= ord("z")
            or ord("0") <= ord(c) <= ord("9")
        )

  #Time Complexity  : O(N)
  #Space Complexity : O(1)



#solution 2
class Solution:
    def isPalindrome(self, s: str) -> bool:
        st = ''
        for i in s:
            if i.isalnum():
                st += i.lower()
        if st == st[::-1]:
            return True

  #Time Complexity  : O(N)
  #Space Complexity : O(N)































