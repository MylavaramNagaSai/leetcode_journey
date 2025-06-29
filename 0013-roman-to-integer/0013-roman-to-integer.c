int romanToInt(char* s) {
    int map[128] = {0};

    // Define values for Roman symbols
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int result = 0;
    int i = 0;

    while (s[i] != '\0') {
        int curr = map[s[i]];
        int next = map[s[i + 1]];

        if (next > curr) {
            result += next - curr;
            i += 2;
        } else {
            result += curr;
            i++;
        }
    }

    return result;
}
