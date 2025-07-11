#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Priority queue for available rooms (room numbers) — min-heap
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i)
            available.push(i);

        // Priority queue for ongoing meetings: (end_time, room_number) — min-heap
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> ongoing;

        // Track how many meetings each room hosted
        vector<int> roomMeetingCount(n, 0);

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];

            // Free rooms whose meetings have ended by `start` time
            while (!ongoing.empty() && ongoing.top().first <= start) {
                available.push(ongoing.top().second);
                ongoing.pop();
            }

            if (!available.empty()) {
                // Assign the meeting to the lowest numbered available room
                int room = available.top();
                available.pop();
                roomMeetingCount[room]++;
                ongoing.emplace(end, room);
            } else {
                // No room is available — delay the meeting
                auto [finishTime, room] = ongoing.top();
                ongoing.pop();
                roomMeetingCount[room]++;
                long long newEnd = finishTime + (end - start);
                ongoing.emplace(newEnd, room);
            }
        }

        // Find room with maximum meetings (lowest number in case of tie)
        int maxCount = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomMeetingCount[i] > maxCount) {
                maxCount = roomMeetingCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
