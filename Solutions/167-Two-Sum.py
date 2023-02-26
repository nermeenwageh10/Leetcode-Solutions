class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
            low=0
            high=len(numbers)-1
            while low<high:
                numSum=numbers[low]+numbers[high]
                if numSum==target:
                    return([low+1,high+1])
                elif numSum>target:
                    high-=1
                elif numSum<target:
                    low+=1
            
                    
