#include <stdlib.h>

// Helper function for backtracking
void backtrack(int* candidates, int candidatesSize, int target, int* combo, int comboSize,
               int** result, int* returnSize, int** returnColumnSizes, int start) {
    if (target == 0) {
        result[*returnSize] = (int*)malloc(sizeof(int) * comboSize);
        memcpy(result[*returnSize], combo, sizeof(int) * comboSize);
        (*returnColumnSizes)[*returnSize] = comboSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) continue;
        combo[comboSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], combo, comboSize + 1,
                  result, returnSize, returnColumnSizes, i);  // not i+1 because reuse is allowed
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {
    int maxCombinations = 150; // estimate upper bound
    int** result = (int**)malloc(sizeof(int*) * maxCombinations);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxCombinations);
    *returnSize = 0;

    int* combo = (int*)malloc(sizeof(int) * target); // worst case: all 1s

    backtrack(candidates, candidatesSize, target, combo, 0,
              result, returnSize, returnColumnSizes, 0);

    free(combo);
    return result;
}
