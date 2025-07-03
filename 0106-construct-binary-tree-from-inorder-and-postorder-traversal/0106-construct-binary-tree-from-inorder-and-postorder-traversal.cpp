class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        int postIdx = postorder.size() - 1;

        return helper(0, inorder.size() - 1, postorder, postIdx, inorderIndex);
    }

private:
    TreeNode* helper(int inLeft, int inRight, vector<int>& postorder, int& postIdx, unordered_map<int, int>& inorderIndex) {
        if (inLeft > inRight) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int inIdx = inorderIndex[rootVal];

        // Build right subtree first because of postorder's nature
        root->right = helper(inIdx + 1, inRight, postorder, postIdx, inorderIndex);
        root->left  = helper(inLeft, inIdx - 1, postorder, postIdx, inorderIndex);

        return root;
    }
};
