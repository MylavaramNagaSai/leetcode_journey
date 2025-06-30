#include <stdlib.h>

void backtrack(int* nums, int numsSize, int start, int* temp, int tempSize, 
               int** result, int* returnSize, int** columnSizes) {
    result[*returnSize] = (int*)malloc(tempSize * sizeof(int));
    for (int i = 0; i < tempSize; i++) result[*returnSize][i] = temp[i];
    (*columnSizes)[*returnSize] = tempSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        temp[tempSize] = nums[i];
        backtrack(nums, numsSize, i + 1, temp, tempSize + 1, result, returnSize, columnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxSubsets = 1 << numsSize;  // 2^n subsets
    int** result = (int**)malloc(maxSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSubsets * sizeof(int));
    int* temp = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    backtrack(nums, numsSize, 0, temp, 0, result, returnSize, returnColumnSizes);
    free(temp);
    return result;
}
