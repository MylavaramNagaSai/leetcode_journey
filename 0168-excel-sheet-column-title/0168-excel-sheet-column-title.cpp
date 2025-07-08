#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--; // shift to 0-based
            int remainder = columnNumber % 26;
            result += ('A' + remainder);
            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
