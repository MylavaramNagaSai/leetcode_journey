#include <string.h>

int strStr(char* haystack, char* needle) {
    int hLen = strlen(haystack);
    int nLen = strlen(needle);

    if (nLen == 0) return 0;

    for (int i = 0; i <= hLen - nLen; i++) {
        int j = 0;
        while (j < nLen && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == nLen) return i;
    }

    return -1;
}
