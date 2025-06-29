#include <stdlib.h>

// Compare function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 4) return NULL;

    qsort(nums, numsSize, sizeof(int), cmp);

    int capacity = 1000;
    int** result = (int**)malloc(capacity * sizeof(int*));
    int* colSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    int* quad = (int*)malloc(4 * sizeof(int));
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];

                    result[*returnSize] = quad;
                    colSizes[*returnSize] = 4;
                    (*returnSize)++;

                    // Resize result buffer if needed
                    if (*returnSize == capacity) {
                        capacity *= 2;
                        result = (int**)realloc(result, capacity * sizeof(int*));
                        colSizes = (int*)realloc(colSizes, capacity * sizeof(int));
                    }

                    // Skip duplicates
                    while (left < right && nums[left] == quad[2]) left++;
                    while (left < right && nums[right] == quad[3]) right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    *returnColumnSizes = colSizes;
    return result;
}
