#include <stdlib.h>
#include <string.h>

char* buildLine(char** words, int start, int end, int numWords, int maxWidth, int isLastLine) {
    char* line = (char*)malloc(maxWidth + 1);
    memset(line, ' ', maxWidth);
    line[maxWidth] = '\0';

    if (numWords == 1 || isLastLine) {
        // Left-justified line
        int pos = 0;
        for (int i = start; i <= end; i++) {
            int len = strlen(words[i]);
            memcpy(line + pos, words[i], len);
            pos += len;
            if (pos < maxWidth) line[pos++] = ' ';
        }
        return line;
    }

    // Fully justified line
    int totalLen = 0;
    for (int i = start; i <= end; i++) {
        totalLen += strlen(words[i]);
    }

    int totalSpaces = maxWidth - totalLen;
    int gaps = numWords - 1;
    int baseSpace = totalSpaces / gaps;
    int extraSpace = totalSpaces % gaps;

    int pos = 0;
    for (int i = start; i < end; i++) {
        int len = strlen(words[i]);
        memcpy(line + pos, words[i], len);
        pos += len;

        int spaceCount = baseSpace + (extraSpace-- > 0 ? 1 : 0);
        for (int s = 0; s < spaceCount; s++) line[pos++] = ' ';
    }

    // Add last word
    memcpy(line + pos, words[end], strlen(words[end]));
    return line;
}

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * (wordsSize + 1));
    int i = 0, start = 0, totalLen = 0;
    int lineWords = 0;
    *returnSize = 0;

    while (i < wordsSize) {
        if (totalLen + lineWords + strlen(words[i]) > maxWidth) {
            result[(*returnSize)++] = buildLine(words, start, i - 1, lineWords, maxWidth, 0);
            start = i;
            totalLen = 0;
            lineWords = 0;
        }
        totalLen += strlen(words[i]);
        lineWords++;
        i++;
    }

    // Handle last line
    result[(*returnSize)++] = buildLine(words, start, i - 1, lineWords, maxWidth, 1);

    return result;
}
