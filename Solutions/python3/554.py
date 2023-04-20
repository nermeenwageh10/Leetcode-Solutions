class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        hm = {0:0} #Ensure hashmap isn't empty at end
        for row in wall:
            s = 0
            for brick in row[:-1]:
                s+=brick
                if not s in hm:
                    hm[s] = 0
                hm[s] += 1
        return len(wall) - max(hm.values())
                
