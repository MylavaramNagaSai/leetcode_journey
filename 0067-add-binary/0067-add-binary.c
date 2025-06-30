#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    
    // Temporary result with extra space for carry and null terminator
    char* temp = (char*)malloc(maxLen + 2); 
    int i = lenA - 1, j = lenB - 1, k = maxLen;
    int carry = 0;

    temp[k + 1] = '\0'; // Null terminator

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        temp[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // If carry is present, k == -1 and result starts at temp[0]
    // If no carry, k >= 0 and result starts at temp[k + 1]
    char* result;
    if (k < 0) {
        result = (char*)malloc(maxLen + 2);
        strcpy(result, temp);
    } else {
        result = (char*)malloc(maxLen + 2 - (k + 1));
        strcpy(result, temp + k + 1);
    }

    free(temp);
    return result;
}
