class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s=s.split()
        return len(s[-1])
