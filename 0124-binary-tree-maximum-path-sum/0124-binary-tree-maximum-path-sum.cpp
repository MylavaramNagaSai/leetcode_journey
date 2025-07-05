class Solution {
    int maxSum;

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        // Recursively get the max gain from left and right subtrees
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // Max path sum with current node as root of the path
        int currentPathSum = node->val + leftGain + rightGain;

        // Update global max if current path sum is greater
        maxSum = max(maxSum, currentPathSum);

        // Return the max gain if we continue the same path from parent
        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }
};
