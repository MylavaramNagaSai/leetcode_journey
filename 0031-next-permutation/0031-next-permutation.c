void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    // Step 1: Find the first index i where nums[i] < nums[i+1]
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Step 2: Find the first index j from the right such that nums[j] > nums[i]
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }

        // Step 3: Swap nums[i] and nums[j]
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Step 4: Reverse the subarray from i+1 to end
    reverse(nums, i + 1, numsSize - 1);
}
