# Definition for a binary tree node.
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def leftDepth(node):
            d = 0
            while node:
                d += 1
                node = node.left
            return d

        def rightDepth(node):
            d = 0
            while node:
                d += 1
                node = node.right
            return d

        if not root:
            return 0

        left = leftDepth(root)
        right = rightDepth(root)

        if left == right:
            # Tree is a perfect binary tree
            return (1 << left) - 1
        else:
            # Recurse on subtrees
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)
