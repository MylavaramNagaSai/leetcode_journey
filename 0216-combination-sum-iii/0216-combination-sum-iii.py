from typing import List

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        result = []

        def backtrack(start: int, path: List[int], remaining: int):
            # Base case: if we picked k numbers and the sum is n
            if len(path) == k and remaining == 0:
                result.append(path[:])
                return
            # Prune the recursion tree
            if len(path) > k or remaining < 0:
                return
            
            for i in range(start, 10):  # Numbers from 1 to 9
                path.append(i)
                backtrack(i + 1, path, remaining - i)
                path.pop()  # Backtrack

        backtrack(1, [], n)
        return result
