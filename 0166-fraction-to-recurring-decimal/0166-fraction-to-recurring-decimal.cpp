#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0))
            result += "-";

        // Convert to long long to avoid overflow
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        // Integer part
        result += to_string(n / d);
        n %= d;

        if (n == 0) return result; // no decimal part

        result += ".";

        unordered_map<long long, int> remainderMap; // remainder → position in result

        while (n != 0) {
            if (remainderMap.count(n)) {
                result.insert(remainderMap[n], "(");
                result += ")";
                break;
            }

            remainderMap[n] = result.length();
            n *= 10;
            result += to_string(n / d);
            n %= d;
        }

        return result;
    }
};
