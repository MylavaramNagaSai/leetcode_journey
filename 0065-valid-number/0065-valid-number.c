#include <ctype.h>
#include <stdbool.h>

bool isNumber(char* s) {
    bool seenDigit = false, seenDot = false, seenExp = false;
    int i = 0;

    // Skip leading spaces
    while (s[i] == ' ') i++;

    // Optional sign
    if (s[i] == '+' || s[i] == '-') i++;

    for (; s[i]; i++) {
        if (isdigit(s[i])) {
            seenDigit = true;
        } else if (s[i] == '.') {
            if (seenDot || seenExp) return false;
            seenDot = true;
        } else if (s[i] == 'e' || s[i] == 'E') {
            if (!seenDigit || seenExp) return false;
            seenExp = true;
            seenDigit = false; // must have digit after e
            if (s[i + 1] == '+' || s[i + 1] == '-') i++; // skip optional sign
        } else if (s[i] == ' ') {
            // Skip trailing spaces, but no non-space allowed afterward
            while (s[i] == ' ') i++;
            return s[i] == '\0';
        } else {
            return false;
        }
    }

    return seenDigit;
}
