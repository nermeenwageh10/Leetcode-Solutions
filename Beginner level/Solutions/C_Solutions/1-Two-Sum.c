int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *ptr = (int *)malloc(2 * sizeof(int));
    if (NULL == ptr)
    {
    }
    else
    {
        int temp = 0;
        for (int i = 0; i < numsSize - 1; i++)
        {
            temp = target - *(nums + i);
            for (int j = i + 1; j < numsSize; j++)
            {
                if (temp == *(nums + j))
                {
                    *ptr = i;
                    *(ptr + 1) = j;
                }
                else
                {
                }
            }
        }
    }
    return ptr;
}