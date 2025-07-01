class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;               // both null
        if (!p || !q) return false;              // one null
        if (p->val != q->val) return false;      // different values

        // Recursively check left and right
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
