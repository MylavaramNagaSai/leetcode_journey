#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while (word.length() < k) {
            string nextPart = "";
            for (char c : word) {
                char nextChar = (c - 'a' + 1) % 26 + 'a';
                nextPart += nextChar;
            }
            word += nextPart;
        }

        return word[k - 1];
    }
};
