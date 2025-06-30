int climbStairs(int n) {
    if (n <= 2) return n;

    int first = 1, second = 2, i;
    for (i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }

    return second;
}
