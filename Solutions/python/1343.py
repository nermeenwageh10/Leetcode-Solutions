class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        windSum=0
        MaxC=0
        for i in range(k):
            windSum+=arr[i]
        if windSum//k >=threshold:
            MaxC+=1
        for i in range(k,len(arr)):
            windSum=windSum-arr[i-k]+arr[i]
            if windSum//k >=threshold:
                MaxC+=1
            continue
        return(MaxC)
