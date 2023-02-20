def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix or not matrix[0]:return []
    
        m, n = len(matrix),len(matrix[0])
        p_visited = set()
        a_visited = set()
        directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        
        def dfs(visited, x,y):
            visited.add((x,y))
            for dx, dy in directions:
                new_x, new_y = x+dx, y+dy
                if 0<=new_x<m and 0<=new_y<n and (new_x,new_y) not in visited and matrix[new_x][new_y]>=matrix[x][y]:
                    dfs(visited, new_x,new_y)
                    
        #iterate from left border and right border
        for i in range(m):
            dfs(p_visited,i,0)
            dfs(a_visited,i,n-1)
            
        #iterate from up border and bottom border
        for j in range(n):
            dfs(p_visited,0,j)
            dfs(a_visited,m-1,j)
            
        #The intersections of two sets are coordinates where water can flow to both P and A
        return list(p_visited.intersection(a_visited))
