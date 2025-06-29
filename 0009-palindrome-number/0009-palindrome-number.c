#include <stdbool.h>

bool isPalindrome(int x) {
    // Negative numbers and numbers ending in 0 (but not 0 itself) are not palindromes
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversed = 0;

    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // For even length: x == reversed
    // For odd length: x == reversed / 10 (middle digit removed)
    return x == reversed || x == reversed / 10;
}
