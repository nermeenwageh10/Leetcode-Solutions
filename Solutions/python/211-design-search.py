class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False
        
class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root
        for w in word:
            if w not in curr.children:
                curr.children[w] = TrieNode()
            curr = curr.children[w]  
        curr.is_word = True    

    def search(self, word: str) -> bool:
        stack = [(self.root,0)]
        while stack:
            curr,idx = stack.pop()
            if idx == len(word):
                if curr.is_word:
                    return True
            elif word[idx] == '.':
                for child in curr.children.values():
                    stack.append((child,idx+1))
            elif word[idx] in curr.children:
                stack.append((curr.children[word[idx]], idx+1))
        return False
        
