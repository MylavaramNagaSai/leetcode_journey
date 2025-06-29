#include <stdlib.h>
#include <string.h>

// Mapping from digit to corresponding letters
const char* mapping[] = {
    "",     "",     "abc",  "def", "ghi",
    "jkl",  "mno",  "pqrs", "tuv", "wxyz"
};

void backtrack(char* digits, int index, char* current, char** result, int* returnSize) {
    if (digits[index] == '\0') {
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    const char* letters = mapping[digits[index] - '0'];
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if (digits[0] == '\0') {
        return NULL;
    }

    char** result = (char**)malloc(sizeof(char*) * 1000);
    char* current = (char*)malloc(sizeof(char) * (strlen(digits) + 1));
    current[strlen(digits)] = '\0';

    backtrack(digits, 0, current, result, returnSize);
    free(current);

    return result;
}
