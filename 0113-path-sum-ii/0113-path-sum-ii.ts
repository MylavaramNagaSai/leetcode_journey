function pathSum(root: TreeNode | null, targetSum: number): number[][] {
    const result: number[][] = [];

    function dfs(node: TreeNode | null, path: number[], sum: number): void {
        if (!node) return;

        path.push(node.val);

        // If it's a leaf and path sum matches, add to result
        if (!node.left && !node.right && sum + node.val === targetSum) {
            result.push([...path]);
        }

        dfs(node.left, path, sum + node.val);
        dfs(node.right, path, sum + node.val);

        path.pop(); // backtrack
    }

    dfs(root, [], 0);
    return result;
}
