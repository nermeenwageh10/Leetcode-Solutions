class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        words.sort()
        d={}
        for word in words:
            d[word]=1+d.get(word,0)
        d=list(dict(sorted(d.items(), key=lambda x:x[1],reverse=True)))[:k]
        return(d)
      
            
