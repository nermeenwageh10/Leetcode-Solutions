int removeElement(int *nums, int numsSize, int val)
{
    int left = 0, right = numsSize - 1, k = 0;
    while (left <= right)
    {
        if (*(nums + left) == val)
        {
            while (left < right)
            {
                if ((*(nums + right) == val))
                {
                    right--;
                    k++;
                }
                else
                {
                    break;
                }
            }
            /*swap*/
            *(nums + left) = *(nums + left) ^ *(nums + right);
            *(nums + right) = *(nums + left) ^ *(nums + right);
            *(nums + left) = *(nums + left) ^ *(nums + right);

            right--;
            k++;
        }
        left++;
    }
    return numsSize - k;
}
