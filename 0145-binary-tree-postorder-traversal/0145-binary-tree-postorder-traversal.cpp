class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        TreeNode* prev = nullptr;

        st.push(root);

        while (!st.empty()) {
            TreeNode* current = st.top();

            // Traverse down the tree
            if (!prev || prev->left == current || prev->right == current) {
                if (current->left) st.push(current->left);
                else if (current->right) st.push(current->right);
                else {
                    result.push_back(current->val);
                    st.pop();
                }
            }
            // Traverse up from left
            else if (current->left == prev) {
                if (current->right) st.push(current->right);
                else {
                    result.push_back(current->val);
                    st.pop();
                }
            }
            // Traverse up from right
            else if (current->right == prev) {
                result.push_back(current->val);
                st.pop();
            }

            prev = current;
        }

        return result;
    }
};
