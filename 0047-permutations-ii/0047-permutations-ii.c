#include <stdlib.h>
#include <string.h>

// Comparator for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Backtracking function (fixed signature)
void backtrack(int* nums, int numsSize, int* used,
               int* current, int depth,
               int** result, int* returnSize, int* returnColumnSizes) {
    if (depth == numsSize) {
        result[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        memcpy(result[*returnSize], current, sizeof(int) * numsSize);
        returnColumnSizes[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;  // Skip duplicates

        used[i] = 1;
        current[depth] = nums[i];
        backtrack(nums, numsSize, used, current, depth + 1,
                  result, returnSize, returnColumnSizes);
        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxPermutations = 1;
    for (int i = 2; i <= numsSize; i++) {
        maxPermutations *= i;
    }

    int** result = (int**)malloc(sizeof(int*) * maxPermutations);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxPermutations);
    *returnSize = 0;

    int* current = (int*)malloc(sizeof(int) * numsSize);
    int* used = (int*)calloc(numsSize, sizeof(int));

    // Sort to make it easier to skip duplicates
    qsort(nums, numsSize, sizeof(int), cmp);

    backtrack(nums, numsSize, used, current, 0,
              result, returnSize, *returnColumnSizes);

    free(current);
    free(used);
    return result;
}
