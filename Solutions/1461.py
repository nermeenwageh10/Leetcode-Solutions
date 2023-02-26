class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        codeSet=set()
        for i in range(len(s)-k+1):
            codeSet.add(s[i:i+k])
        if len(codeSet)==2**k:
            return(True)
        else:
            return(False)
