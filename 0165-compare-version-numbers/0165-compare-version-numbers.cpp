#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);

        int n = max(v1.size(), v2.size());

        for (int i = 0; i < n; ++i) {
            int rev1 = (i < v1.size()) ? v1[i] : 0;
            int rev2 = (i < v2.size()) ? v2[i] : 0;

            if (rev1 < rev2) return -1;
            if (rev1 > rev2) return 1;
        }

        return 0;
    }

private:
    vector<int> split(const string& version) {
        vector<int> res;
        stringstream ss(version);
        string token;
        while (getline(ss, token, '.')) {
            res.push_back(stoi(token)); // handles leading zeros
        }
        return res;
    }
};
