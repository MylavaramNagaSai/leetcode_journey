#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // Peak is on the left side (including mid)
                right = mid;
            } else {
                // Peak is on the right side
                left = mid + 1;
            }
        }

        return left; // or right (same when loop ends)
    }
};
