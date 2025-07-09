class Solution {
public:
    static bool compare(string &a, string &b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        sort(strs.begin(), strs.end(), compare);

        // Edge case: all zeros
        if (strs[0] == "0") return "0";

        string result;
        for (string& s : strs) {
            result += s;
        }

        return result;
    }
};
