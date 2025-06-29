#include <ctype.h>
#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    long result = 0;
    int sign = 1;

    // 1. Skip leading whitespaces
    while (s[i] == ' ') i++;

    // 2. Handle optional sign
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // 3. Read digits and build the result
    while (isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');

        // 4. Clamp if overflow occurs
        if (sign == 1 && result > INT_MAX) return INT_MAX;
        if (sign == -1 && -result < INT_MIN) return INT_MIN;

        i++;
    }

    return (int)(sign * result);
}
