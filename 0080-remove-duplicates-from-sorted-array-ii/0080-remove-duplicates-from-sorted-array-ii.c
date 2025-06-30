int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize;

    int write = 2;
    for (int read = 2; read < numsSize; read++) {
        if (nums[read] != nums[write - 2]) {
            nums[write++] = nums[read];
        }
    }
    return write;
}
