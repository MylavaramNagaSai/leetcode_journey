from typing import List

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        num_map = {}  # maps number to its last seen index
        for i, num in enumerate(nums):
            if num in num_map and i - num_map[num] <= k:
                return True
            num_map[num] = i  # update last seen index
        return False
