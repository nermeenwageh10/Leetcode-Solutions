class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        
        right_force = [0] * n
        
        for i in range(n):
            if dominoes[i] == 'R':
                right_force[i] = n
            elif dominoes[i] == 'L':
                right_force[i] = 0
            else:
                if(i-1 >= 0):
                    right_force[i] = max(right_force[i-1]-1, 0)

        left_force = [0] * n
        
        for i in range(n-1, -1, -1):
            if dominoes[i] == 'L':
                left_force[i] = n
            elif dominoes[i] == 'R':
                left_force[i] = 0
            else:
                if(i+1 < n):
                    left_force[i] = max(left_force[i+1]-1, 0)
    
        return ''.join('.' if right_force[i] == left_force[i] else 'R' if right_force[i] > left_force[i] else 'L' for i in range(n))
        
