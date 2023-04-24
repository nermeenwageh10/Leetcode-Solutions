int pivotIndex(int *nums, int numsSize)
{
    int leftArraySum = 0;
    int rightArraySum = 0;

    for (int i = 1; i < numsSize; i++)
    {
        rightArraySum += *(nums + i);
    }

    for (int i = 0; i < numsSize - 1; i++)
    {
        if (leftArraySum == rightArraySum)
        {
            return i;
        }
        else
        {
            leftArraySum += *(nums + i);
            rightArraySum -= *(nums + i + 1);
        }
    }
    if (leftArraySum == rightArraySum)
    {
        return numsSize - 1;
    }
    return -1;
}