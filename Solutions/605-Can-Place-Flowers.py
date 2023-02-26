class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:

        if len(flowerbed) == 0:
            return False
        if len(flowerbed) == 1 and flowerbed[0] == 1 and n == 1:
            return False
        elif len(flowerbed) == 1:
            return True

        # starting case
        if flowerbed[0] == 0 and flowerbed[1] == 0:
            n -= 1
            flowerbed[0] = 1

        # n limit checks
        if n <= 0:
            return True

        for i in range(1, len(flowerbed)-1):
            # middle cases
            if flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                n -= 1
                flowerbed[i] = 1
        
        # n limit checks
        if n <= 0:
            return True

        # ending cases
        if flowerbed[len(flowerbed) - 1] == 0 and flowerbed[len(flowerbed) - 2] == 0:
            n -= 1
            flowerbed[len(flowerbed) - 1] == 1

        if n <= 0:
            return True
        return False
