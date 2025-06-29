int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int writeIndex = 1;

    for (int readIndex = 1; readIndex < numsSize; readIndex++) {
        if (nums[readIndex] != nums[readIndex - 1]) {
            nums[writeIndex++] = nums[readIndex];
        }
    }

    return writeIndex;
}
