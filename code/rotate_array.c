#include <stdlib.h>
#include <string.h>

void rotate(int *nums, int numsSize, int k)
{
    k = k % numsSize;
    int *temp = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < k; i++)
    {
        *(temp + i) = *(nums + numsSize - k + i);
    }

    for (int i = 0; i < numsSize - k; i++)
    {
        *(temp + i + k) = *(nums + i);
    }

    memcpy(nums, temp, numsSize * sizeof(int));
    free(temp);
}