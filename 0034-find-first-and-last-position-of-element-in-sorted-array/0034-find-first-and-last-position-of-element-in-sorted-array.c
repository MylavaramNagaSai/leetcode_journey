void binarySearch(int* nums, int numsSize, int target, int* result) {
    int left = 0, right = numsSize - 1;
    result[0] = result[1] = -1;

    // Find leftmost (first) index
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (left >= numsSize || nums[left] != target) return;
    result[0] = left;

    // Find rightmost (last) index
    right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    result[1] = right;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int) * 2);
    binarySearch(nums, numsSize, target, result);
    return result;
}
