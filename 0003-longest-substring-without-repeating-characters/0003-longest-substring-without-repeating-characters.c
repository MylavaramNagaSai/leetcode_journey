#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lastIndex[128]; // ASCII characters
    for (int i = 0; i < 128; i++) {
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (lastIndex[c] >= start) {
            start = lastIndex[c] + 1;
        }

        lastIndex[c] = i;

        int currentLen = i - start + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}
