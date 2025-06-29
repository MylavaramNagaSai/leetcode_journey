#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    // Roman numeral values and their corresponding symbols
    int values[] =    {1000, 900, 500, 400, 100,  90,  50,  40,  10,   9,   5,   4,   1};
    const char* syms[] = {"M", "CM","D", "CD","C","XC","L","XL","X","IX","V","IV","I"};

    // Max result length: Roman numeral for 3999 is "MMMCMXCIX" (length 15)
    char* result = (char*)malloc(20);
    result[0] = '\0'; // Start with empty string

    for (int i = 0; i < 13 && num > 0; i++) {
        while (num >= values[i]) {
            strcat(result, syms[i]);
            num -= values[i];
        }
    }

    return result;
}
