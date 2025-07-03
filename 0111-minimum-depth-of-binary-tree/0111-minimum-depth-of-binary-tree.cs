public class Solution {
    public int MinDepth(TreeNode root) {
        if (root == null) return 0;

        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);
        int depth = 1;

        while (queue.Count > 0) {
            int levelSize = queue.Count;

            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.Dequeue();

                // If it's a leaf node, return the depth
                if (node.left == null && node.right == null)
                    return depth;

                if (node.left != null)
                    queue.Enqueue(node.left);
                if (node.right != null)
                    queue.Enqueue(node.right);
            }

            depth++;
        }

        return depth;
    }
}
