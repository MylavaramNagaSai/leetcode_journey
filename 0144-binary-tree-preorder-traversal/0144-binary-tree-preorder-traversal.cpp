class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top(); s.pop();
            result.push_back(node->val);
            
            if (node->right) s.push(node->right); // right pushed first
            if (node->left) s.push(node->left);   // left pushed second
        }

        return result;
    }
};