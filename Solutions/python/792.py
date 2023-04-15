class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        word_count={}
        for word in words:
            word_count[word]=word_count.get(word,0)+1
        
        def is_subsequence(s,word):
            i=0
            for char in word:
                i=s.find(char,i)+1
                if not i :
                    return False
            return True
        res=0
        for word in word_count:
            if is_subsequence(s,word):
                res+=word_count[word]
        return res
