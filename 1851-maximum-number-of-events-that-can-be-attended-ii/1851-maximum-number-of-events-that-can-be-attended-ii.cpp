#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        
        // Sort events by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Precompute the previous non-overlapping event index for each event
        vector<int> prev(n, -1);
        for (int i = 0; i < n; ++i) {
            int l = 0, r = i - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (events[m][1] < events[i][0]) {
                    prev[i] = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        
        // dp[i][j]: max value by attending at most j events from first i events
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // Don't attend this event
                dp[i][j] = dp[i - 1][j];
                
                // Attend this event
                int include = events[i - 1][2];
                if (prev[i - 1] != -1)
                    include += dp[prev[i - 1] + 1][j - 1];
                else
                    include += 0;
                
                dp[i][j] = max(dp[i][j], include);
            }
        }
        
        return dp[n][k];
    }
};
