class Solution {
public:
    vector<string> result;

    void backtrack(string& s, int start, int dots, string current) {
        if (dots == 4 && start == s.size()) {
            result.push_back(current.substr(0, current.size() - 1)); // remove trailing dot
            return;
        }

        if (dots > 4) return;

        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.size()) break;
            string part = s.substr(start, len);

            // Skip invalid segments
            if ((part[0] == '0' && part.length() > 1) || stoi(part) > 255)
                continue;

            backtrack(s, start + len, dots + 1, current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12) return {};
        backtrack(s, 0, 0, "");
        return result;
    }
};
