class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to long long and work with positive values
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        long long result = 0;

        // Repeatedly subtract multiples of divisor from dividend
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            result += multiple;
        }

        return negative ? -result : result;
    }
};
