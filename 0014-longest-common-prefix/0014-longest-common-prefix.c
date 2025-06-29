#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    int index = 0;
    while (1) {
        char c = strs[0][index];
        if (c == '\0') break;

        for (int i = 1; i < strsSize; i++) {
            if (strs[i][index] != c || strs[i][index] == '\0') {
                goto end;
            }
        }

        index++;
    }

end:
    char* prefix = (char*)malloc(index + 1);
    strncpy(prefix, strs[0], index);
    prefix[index] = '\0';
    return prefix;
}
