from typing import List
import heapq

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []
        for left, right, height in buildings:
            # Building start marked with -height for max heap
            events.append((left, -height, right))
            # Building end marked with 0 height
            events.append((right, 0, 0))
        
        # Sort events: first by x, then by height
        events.sort()

        result = []
        # Heap: (-height, end)
        live = [(0, float('inf'))]
        prev_max = 0

        for x, neg_h, r in events:
            # Remove buildings from heap whose right edge is <= x
            while live[0][1] <= x:
                heapq.heappop(live)
            if neg_h != 0:
                # Add new building
                heapq.heappush(live, (neg_h, r))
            current_max = -live[0][0]
            if current_max != prev_max:
                result.append([x, current_max])
                prev_max = current_max

        return result
