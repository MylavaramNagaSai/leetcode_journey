class Solution {
public:
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                second = root;
            } else {
                second = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
