class Solution:
    def sortedArrayToBST(self, nums):
        if not nums:
            return None

        def helper(left, right):
            if left > right:
                return None

            mid = (left + right) // 2
            root = TreeNode(nums[mid])

            root.left = helper(left, mid - 1)
            root.right = helper(mid + 1, right)

            return root

        return helper(0, len(nums) - 1)
