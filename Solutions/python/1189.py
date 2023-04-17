class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        d={}
        wordCnt={}
        word="balloon"
        for i in text:
            d[i]=1+d.get(i,0)
        for i in word:
            if i in d:
                wordCnt[i]=d[i]
        if sum(wordCnt.values())>=len(word):
            return((min(wordCnt['b'],wordCnt['a'],wordCnt['l']//2,wordCnt['o']//2,wordCnt['n'])))
        else:
            return(0)
            
