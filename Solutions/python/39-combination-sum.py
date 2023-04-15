class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result=[]
        
        def dfs(total,subset):
            if total==target:
                subset.sort()
                if (subset) not in result:
                    result.append(subset)
                return True
            if total > target:
                return False
            diff=target-total
            for num in candidates:
                if num>diff:
                    continue
                level=subset.copy()
                level.append(num)
                dfs(total+num,level)
        dfs(0,[])
        return result
                
