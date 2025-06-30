char* getPermutation(int n, int k) {
    int fact = 1;
    int i, j;
    char* res = (char*)malloc((n + 1) * sizeof(char));
    int* numbers = (int*)malloc(n * sizeof(int));

    // Initialize factorial and numbers list
    for (i = 1; i <= n; i++) {
        fact *= i;
        numbers[i - 1] = i;
    }

    k--; // convert to 0-indexed
    res[n] = '\0'; // null-terminate

    for (i = 0; i < n; i++) {
        fact /= (n - i);
        int index = k / fact;
        res[i] = numbers[index] + '0';

        // Remove the used number
        for (j = index; j < n - i - 1; j++) {
            numbers[j] = numbers[j + 1];
        }

        k %= fact;
    }

    free(numbers);
    return res;
}
