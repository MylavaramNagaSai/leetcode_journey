#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                // Minimum is in left half (including mid)
                right = mid;
            } else if (nums[mid] > nums[right]) {
                // Minimum is in right half (excluding mid)
                left = mid + 1;
            } else {
                // nums[mid] == nums[right], can't decide, safely shrink right
                right--;
            }
        }

        return nums[left];
    }
};
