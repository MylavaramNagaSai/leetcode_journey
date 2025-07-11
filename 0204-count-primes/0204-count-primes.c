int countPrimes(int n) {
    if (n <= 2) return 0;

    // Create a boolean array "isPrime[0..n)" and initialize
    bool* isPrime = (bool*)malloc(n * sizeof(bool));
    for (int i = 2; i < n; ++i)
        isPrime[i] = true;

    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }

    int count = 0;
    for (int i = 2; i < n; ++i)
        if (isPrime[i])
            count++;

    free(isPrime);
    return count;
}
