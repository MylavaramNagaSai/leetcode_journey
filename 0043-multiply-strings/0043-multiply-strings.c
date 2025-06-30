#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 0 || len2 == 0) return "0";
    if (num1[0] == '0' || num2[0] == '0') return strdup("0");

    int* result = (int*)calloc(len1 + len2, sizeof(int));

    // Multiply each digit
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;

            int sum = mul + result[p2];
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }

    // Convert result array to string
    char* resStr = (char*)malloc(len1 + len2 + 1);
    int k = 0, i = 0;
    while (i < len1 + len2 && result[i] == 0) i++;  // Skip leading zeros
    for (; i < len1 + len2; i++) {
        resStr[k++] = result[i] + '0';
    }
    resStr[k] = '\0';

    free(result);

    return k == 0 ? strdup("0") : resStr;
}
