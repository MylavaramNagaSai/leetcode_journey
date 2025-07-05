class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;

        currentSum = currentSum * 10 + node->val;

        // If it's a leaf, return the full number
        if (!node->left && !node->right) {
            return currentSum;
        }

        // Otherwise, recurse left and right
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};
