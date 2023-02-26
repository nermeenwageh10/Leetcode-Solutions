class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        freq = {}
        for i in range(len(s) - 9):
            substring = s[i:i+10]
            freq[substring] = freq.get(substring, 0) + 1
        return [substring for substring in freq if freq[substring] > 1]
