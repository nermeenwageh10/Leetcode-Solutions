class Solution:
    def longestWord(self, words: List[str]) -> str:
        words.sort()
        visited ={""}
        res=""

        for word in words:
            print(word[:-1])
            if word[:-1] in visited:
                visited.add(word)
                if len(word)>len(res):
                    res=word
        return res
        
