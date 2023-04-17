class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        r,c,n=len(board),len(board[0]),len(word)
        visited=set()
        
        def rec(row,col,i,checkstr):
            if i ==len(word):
                return True
            if checkstr==word:
                return True 
            if row<0 or row>=r or col >=c or col<0 :
                return False  
            if (row,col) in visited:
                return False
            else:
                visited.add((row,col))
            if board[row][col]==word[i]:
                if rec(row+1,col,i+1,checkstr+word[i]) or rec(row-1,col,i+1,checkstr+word[i]) or rec(row,col+1,i+1,checkstr+word[i])or rec(row,col-1,i+1,checkstr+word[i]) :
                    return True 
            
            visited.remove((row,col))

        count=defaultdict(int,sum(map(Counter,board),Counter()))
        if count[word[0]] > count[word[-1]]:
            word = word[::-1]

        for m in range(r):
            for n in range(c):
                if rec(m,n,0,""):
                    return True
        return False

















