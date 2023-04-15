class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        if not t: return ""  # edge case
		
        window, countT = {}, {}
        for c in t:
            countT[c] = 1 + countT.get(c, 0)       #Count chars in t
            
		l = 0
        have, need = 0, len(countT)     
        res, resLen = [-1, -1], inf
        
        for r in range(len(s)):
            c = s[r]
            if c in countT:
                window[c] = 1 + window.get(c, 0)      # if c is in countT than inc the value in window 
                
            if c in countT and window[c] == countT[c]:
                have += 1     # if any char is satisfied than inc have
            
            while have == need:
                cl = s[l]
                
                if (r-l+1) < resLen:
                    res = [l, r]
                    resLen = r-l+1 #storing res coz we found our substr
                
                if cl in countT:
                    window[cl] = window.get(cl, 1) - 1    ''' dec count if left char is in countT else skip'''
                
                if cl in countT and window[cl] < countT[cl]:
                    have -= 1   #dec have id cl is less than required in window
                        
                l += 1
                
                
        return s[res[0]: res[1]+1] if resLen != inf else ""
      
      #Time:O(n)
      #Space:O(n) 
