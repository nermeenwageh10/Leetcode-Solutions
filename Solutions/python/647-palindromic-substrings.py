class Solution:
    def countSubstrings(self, s: str) -> int:
	    L, r = len(s), 0
	    for i in range(L):
	    	for a,b in [(i,i),(i,i+1)]:
	    		while a >= 0 and b < L and s[a] == s[b]: a -= 1; b += 1
	    		r += (b-a)//2
	    return r
