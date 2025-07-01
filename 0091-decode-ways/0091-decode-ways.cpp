class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0); // dp[i] = number of ways to decode s[0..i-1]

        dp[0] = 1;  // Empty string
        dp[1] = 1;  // One character (already checked it's not '0')

        for (int i = 2; i <= n; ++i) {
            int oneDigit = s[i - 1] - '0';
            int twoDigit = stoi(s.substr(i - 2, 2));

            if (oneDigit >= 1 && oneDigit <= 9)
                dp[i] += dp[i - 1];

            if (twoDigit >= 10 && twoDigit <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};
