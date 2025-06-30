#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* intA = *(int**)a;
    int* intB = *(int**)b;
    return intA[0] - intB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);
    *returnSize = 0;

    // Initialize first merged interval
    result[0] = (int*)malloc(sizeof(int) * 2);
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;
    *returnSize = 1;

    for (int i = 1; i < intervalsSize; i++) {
        int* last = result[*returnSize - 1];
        int* current = intervals[i];

        if (current[0] <= last[1]) {
            if (current[1] > last[1]) {
                last[1] = current[1];
            }
        } else {
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = current[0];
            result[*returnSize][1] = current[1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }

    return result;
}
