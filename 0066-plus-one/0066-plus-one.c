int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));

    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        result[i + 1] = sum % 10;
        carry = sum / 10;
    }

    if (carry) {
        result[0] = 1;
        *returnSize = digitsSize + 1;
        return result;
    } else {
        // Shift result pointer by 1 to skip the leading 0
        *returnSize = digitsSize;
        return result + 1;
    }
}
