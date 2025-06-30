#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    if (n == 1) {
        char* result = (char*)malloc(2);
        strcpy(result, "1");
        return result;
    }

    char* prev = countAndSay(n - 1);
    int len = strlen(prev);
    char* result = (char*)malloc(len * 2 + 1);  // Allocate enough space
    int idx = 0;

    for (int i = 0; i < len;) {
        char digit = prev[i];
        int count = 0;
        while (i < len && prev[i] == digit) {
            count++;
            i++;
        }
        idx += sprintf(result + idx, "%d%c", count, digit);
    }

    free(prev);
    result[idx] = '\0';
    return result;
}
