class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top(); st.pop();
        int result = node->val;
        if (node->right) {
            pushLeft(node->right);
        }
        return result;
    }

    bool hasNext() {
        return !st.empty();
    }
};
