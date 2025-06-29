#include <string.h>
#include <stdlib.h>

// Helper to expand around the center and return length
int expandFromCenter(char* s, int left, int right, int len) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int start = 0, end = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int len1 = expandFromCenter(s, i, i, len);     // Odd length
        int len2 = expandFromCenter(s, i, i + 1, len); // Even length
        int maxLen = len1 > len2 ? len1 : len2;

        if (maxLen > end - start) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    int resultLen = end - start + 1;
    char* result = (char*)malloc(resultLen + 1);
    strncpy(result, s + start, resultLen);
    result[resultLen] = '\0';

    return result;
}
