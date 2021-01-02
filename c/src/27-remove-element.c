#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
    int i = 0;
    for (int j = 0; j < numsSize; ++j)
    {
        if (nums[j] != val)
        {
            nums[i++] = nums[j];
        }
    }

    return i;
}

int main()
{
    int nums[8] = {0, 1, 2, 2, 3, 0, 4, 2};

    int len = removeElement(nums, 8, 2);

    for (int i = 0; i < len; i++)
    {
        printf("%d%c", nums[i], i == len - 1 ? '\n' : ',');
    }

    return 0;
}