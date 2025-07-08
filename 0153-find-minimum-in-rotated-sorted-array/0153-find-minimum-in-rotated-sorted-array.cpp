#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Min is in the right half
                left = mid + 1;
            } else {
                // Min is in the left half (including mid)
                right = mid;
            }
        }

        return nums[left]; // or nums[right]
    }
};
