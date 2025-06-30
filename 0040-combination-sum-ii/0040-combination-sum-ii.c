#include <stdlib.h>
#include <string.h>

// Comparator function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Backtracking helper
void backtrack(int* candidates, int candidatesSize, int target,
               int* combination, int combSize,
               int** result, int* returnSize, int* returnColumnSizes,
               int start) {
    if (target == 0) {
        result[*returnSize] = (int*)malloc(sizeof(int) * combSize);
        memcpy(result[*returnSize], combination, sizeof(int) * combSize);
        returnColumnSizes[*returnSize] = combSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;  // skip duplicates
        if (candidates[i] > target) break;

        combination[combSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i],
                  combination, combSize + 1,
                  result, returnSize, returnColumnSizes, i + 1);  // i+1: use each number once
    }
}

// Main function to be submitted on LeetCode
int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int maxResults = 200;

    int** result = (int**)malloc(sizeof(int*) * maxResults);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxResults);
    int* combination = (int*)malloc(sizeof(int) * candidatesSize);  // max possible length

    // Sort to manage duplicates
    qsort(candidates, candidatesSize, sizeof(int), cmp);

    backtrack(candidates, candidatesSize, target, combination, 0,
              result, returnSize, *returnColumnSizes, 0);

    free(combination);
    return result;
}
