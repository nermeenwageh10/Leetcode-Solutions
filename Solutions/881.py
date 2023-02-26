class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        c,n=0,len(people)
        i,j=0,n-1
        people.sort()
        while i<=j:
            if people[i]+people[j]<=limit:
                i+=1
                j-=1
            else:
                j-=1
            c+=1
        return c
