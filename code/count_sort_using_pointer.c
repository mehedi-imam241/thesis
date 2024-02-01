
#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, int size)
{
    int *output = (int *)malloc(size * sizeof(int));
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    int *count = (int *)malloc((max + 1) * sizeof(int));

    printf("%d", count);

    for (int i = 0; i < max + 1; i++)
    {
        *(count + i) = 0;
    }

    for (int i = 0; i < size; i++)
    {
        // count[array[i]]++;

        *(count + *(array + i)) = *(count + *(array + i)) + 1;
    }

    for (int i = 1; i < max + 1; i++)
    {
        // count[i] += count[i - 1];
        *(count + i) = *(count + i) + *(count + i - 1);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        // output[count[array[i]] - 1] = array[i];
        // count[array[i]]--;
        *(output + *(count + *(array + i)) - 1) = *(array + i);
        *(count + *(array + i)) = *(count + *(array + i)) - 1;
    }

    for (int i = 0; i < size; i++)
    {
        // array[i] = output[i];
        *(array + i) = *(output + i);
    }
}

// int main(void)
// {
//     int *array = (int *)malloc(10 * sizeof(int));

//     // fill the array with random numbers
//     for (int i = 0; i < 10; i++)
//     {
//         *(array + i) = rand() % 10;
//     }

//     // print the array
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%d ", *(array + i));
//     }

//     printf("\n");

//     bucketSorting(array, 10);

//     for (int i = 0; i < 10; i++)
//     {
//         printf("%d ", *(array + i));
//     }

//     printf("\n");
// }