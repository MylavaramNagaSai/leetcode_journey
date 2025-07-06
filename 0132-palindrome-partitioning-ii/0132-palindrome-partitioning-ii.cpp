class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> minCuts(n, 0);

        for (int i = 0; i < n; ++i) {
            minCuts[i] = i;  // max cuts: one for each character
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || isPalindrome[j + 1][i - 1])) {
                    isPalindrome[j][i] = true;
                    if (j == 0)
                        minCuts[i] = 0;
                    else
                        minCuts[i] = min(minCuts[i], minCuts[j - 1] + 1);
                }
            }
        }

        return minCuts[n - 1];
    }
};

