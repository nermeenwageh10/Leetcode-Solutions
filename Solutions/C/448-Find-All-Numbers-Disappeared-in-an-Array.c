int compare(const void *a, const void *b);
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    int *ptr = (int *)malloc(*(nums + numsSize - 1) * sizeof(int));
    for (int i = 1; i < *nums; i++)
    {
        *(ptr + (*returnSize)) = i;
        (*returnSize)++;
    }
    int dif = 0; /*difference between two numbers*/
    for (int i = 0; i < numsSize - 1; i++)
    {
        dif = *(nums + i + 1) - *(nums + i);
        for (int j = 1; j < dif; j++)
        {
            *(ptr + (*returnSize)) = *(nums + i) + j;
            (*returnSize)++;
        }
    }
    for (int i = (*(nums + numsSize - 1)) + 1; i <= numsSize; i++)
    {
        *(ptr + (*returnSize)) = i;
        (*returnSize)++;
    }
    return ptr;
}

int compare(const void *a, const void *b)
{
    return (*((int *)a) - *((int *)b));
}