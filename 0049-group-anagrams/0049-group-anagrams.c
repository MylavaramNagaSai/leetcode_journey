#include <stdlib.h>
#include <string.h>

char* sortString(char* str) {
    int len = strlen(str);
    char* sorted = strdup(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (sorted[i] > sorted[j]) {
                char temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    return sorted;
}

typedef struct {
    char* key;
    char** group;
    int size;
    int capacity;
} AnagramGroup;

int isSameKey(char* a, char* b) {
    return strcmp(a, b) == 0;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int maxGroups = strsSize;
    AnagramGroup* groups = malloc(sizeof(AnagramGroup) * maxGroups);
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        char* sorted = sortString(strs[i]);
        int found = 0;

        for (int j = 0; j < groupCount; j++) {
            if (isSameKey(groups[j].key, sorted)) {
                if (groups[j].size >= groups[j].capacity) {
                    groups[j].capacity *= 2;
                    groups[j].group = realloc(groups[j].group, sizeof(char*) * groups[j].capacity);
                }
                groups[j].group[groups[j].size++] = strs[i];
                found = 1;
                break;
            }
        }

        if (!found) {
            groups[groupCount].key = sorted;
            groups[groupCount].capacity = 4;
            groups[groupCount].size = 1;
            groups[groupCount].group = malloc(sizeof(char*) * groups[groupCount].capacity);
            groups[groupCount].group[0] = strs[i];
            groupCount++;
        } else {
            free(sorted); // don't leak unused sorted strings
        }
    }

    char*** result = malloc(sizeof(char**) * groupCount);
    *returnColumnSizes = malloc(sizeof(int) * groupCount);
    *returnSize = groupCount;

    for (int i = 0; i < groupCount; i++) {
        result[i] = groups[i].group;
        (*returnColumnSizes)[i] = groups[i].size;
        free(groups[i].key); // free sorted key
    }

    free(groups);
    return result;
}
