#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        vector<string> result;

        if (s.length() < 10) return result;

        for (int i = 0; i <= s.length() - 10; ++i) {
            string substring = s.substr(i, 10);
            if (seen.count(substring)) {
                repeated.insert(substring);
            } else {
                seen.insert(substring);
            }
        }

        for (const string& seq : repeated) {
            result.push_back(seq);
        }

        return result;
    }
};
