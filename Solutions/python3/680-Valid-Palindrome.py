class Solution:
    def validPalindrome(self, s: str) -> bool:
        def ispalindrome(s):
            l,r=0,len(s)-1
            while l<r:
                if s[l]!=s[r]:
                    return False
                l+=1
                r-=1
            return True 

        l,r=0,len(s)-1

        while l<r:
            if s[l] != s[r]:
                return ispalindrome(s[l:r]) or ispalindrome(s[l+1:r+1])

            l+=1
            r-=1
        return True
