class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Only start counting when this number is the start of a sequence
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int length = 1;

                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
