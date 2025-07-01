class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

private:
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> trees;

        if (start > end) {
            trees.push_back(nullptr); // Empty tree
            return trees;
        }

        for (int i = start; i <= end; ++i) {
            // All possible left and right subtrees
            vector<TreeNode*> leftTrees = build(start, i - 1);
            vector<TreeNode*> rightTrees = build(i + 1, end);

            // Combine left and right with root i
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }
};
