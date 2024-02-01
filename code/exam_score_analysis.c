// this problem is to analyze the scores of students in an exam using pointer
// we have to output the mode of the scores, the average of the scores, and the median of the scores

#include <stdio.h>
#include <stdlib.h>
#include "count_sort_using_pointer.c"

float calculateMode(int *score, int n)
{
    int maxCount = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (*(score + i) == *(score + j))
            {
                // *(score+i) == (score+j) is not allowed because *(score+i) is an int
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            max = *(score + i);
        }
    }
    return max;
}

float calculateAverage(int *score, int n)
{
    float sum = 0;

    for (int i = 0; i <= n; i++)
    {
        sum += *(score + i);
    }

    return sum / n;
}

float calculateMedian(int *score, int n)
{
    counting_sort(score, n);

    if (n % 2 == 0)
    {
        return (*(score + n / 2) + *(score + n / 2 - 1)) / 2;
    }
    else
    {
        return *(score + n / 2);
    }
}

int main(void)
{
    int n = 7;

    int *score = (int *)malloc(n * sizeof(int));

    printf("%d %d\n", score, score + n);

    for (int i = 0; i < n; i++)
    {
        *(score + i) = rand() % 5;
        // (score+i) = rand() % 10 is not allowed because (score+i) is a pointer
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(score + i));
    }
    printf("\n");

    float average = calculateAverage(score, n);

    printf("The average of the scores is %.2f\n", average);

    float mode = calculateMode(score, n);

    printf("The mode of the scores is %.2f\n", mode);

    float median = calculateMedian(score, n);

    printf("The median of the scores is %.2f\n", median);
}