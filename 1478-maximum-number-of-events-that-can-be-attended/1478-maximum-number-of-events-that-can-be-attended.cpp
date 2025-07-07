class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day
        sort(events.begin(), events.end());

        // Min-heap to store end days
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int i = 0, res = 0, day = 0;
        int n = events.size();

        // Find the last possible day
        int lastDay = 0;
        for (const auto& e : events)
            lastDay = max(lastDay, e[1]);

        for (day = 1; day <= lastDay; ++day) {
            // Add all events starting today
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                ++i;
            }

            // Remove expired events
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend event with earliest end day
            if (!minHeap.empty()) {
                minHeap.pop();
                ++res;
            }
        }

        return res;
    }
};
