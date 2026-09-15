#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Sort intervals according to starting time
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // Allocate result
    int **result = (int **)malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));

    int count = 0;

    // Start with first interval
    result[0] = (int *)malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;
    count = 1;

    for (int i = 1; i < intervalsSize; i++) {

        // If intervals overlap
        if (intervals[i][0] <= result[count - 1][1]) {

            // Extend the ending point if needed
            if (intervals[i][1] > result[count - 1][1]) {
                result[count - 1][1] = intervals[i][1];
            }

        } 
        else {
            // No overlap, create a new interval
            result[count] = (int *)malloc(2 * sizeof(int));

            result[count][0] = intervals[i][0];
            result[count][1] = intervals[i][1];

            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    *returnSize = count;

    return result;
}