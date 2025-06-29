#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || numRows >= strlen(s)) {
        return strdup(s);
    }

    int len = strlen(s);
    char** rows = (char**)malloc(sizeof(char*) * numRows);
    int* pos = (int*)calloc(numRows, sizeof(int));
    
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc(len + 1);
        rows[i][0] = '\0';
    }

    int currRow = 0;
    int goingDown = 0;

    for (int i = 0; i < len; i++) {
        int p = pos[currRow];
        rows[currRow][p] = s[i];
        pos[currRow]++;
        rows[currRow][pos[currRow]] = '\0';

        if (currRow == 0 || currRow == numRows - 1) {
            goingDown = !goingDown;
        }

        currRow += goingDown ? 1 : -1;
    }

    char* result = (char*)malloc(len + 1);
    result[0] = '\0';

    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]);
    }

    free(rows);
    free(pos);
    return result;
}
