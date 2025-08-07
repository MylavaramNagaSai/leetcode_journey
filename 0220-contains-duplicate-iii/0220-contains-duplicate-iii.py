from typing import List

class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        if valueDiff < 0:
            return False

        bucket_size = valueDiff + 1
        buckets = {}

        for i, num in enumerate(nums):
            # Use Python's default floor division — DO NOT adjust for negatives
            bucket_id = num // bucket_size

            # Check current bucket
            if bucket_id in buckets:
                return True

            # Check neighbors
            if (bucket_id - 1 in buckets and abs(num - buckets[bucket_id - 1]) < bucket_size):
                return True
            if (bucket_id + 1 in buckets and abs(num - buckets[bucket_id + 1]) < bucket_size):
                return True

            # Add to bucket
            buckets[bucket_id] = num

            # Maintain sliding window of size indexDiff
            if i >= indexDiff:
                old_bucket_id = nums[i - indexDiff] // bucket_size
                del buckets[old_bucket_id]

        return False
