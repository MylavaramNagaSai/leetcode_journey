from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        def rob_linear(houses):
            prev, curr = 0, 0
            for h in houses:
                prev, curr = curr, max(curr, prev + h)
            return curr
        
        # Case 1: Exclude last house
        case1 = rob_linear(nums[:-1])
        # Case 2: Exclude first house
        case2 = rob_linear(nums[1:])
        
        return max(case1, case2)
