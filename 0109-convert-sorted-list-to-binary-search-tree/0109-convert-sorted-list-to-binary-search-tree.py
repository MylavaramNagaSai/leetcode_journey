class Solution:
    def sortedListToBST(self, head):
        if not head:
            return None

        # Helper to find the middle node
        def find_middle(start):
            prev = None
            slow = start
            fast = start

            while fast and fast.next:
                prev = slow
                slow = slow.next
                fast = fast.next.next

            if prev:
                prev.next = None  # Split the list

            return slow

        # Base case: only one node
        if not head.next:
            return TreeNode(head.val)

        mid = find_middle(head)
        root = TreeNode(mid.val)

        # Left half forms left subtree
        root.left = self.sortedListToBST(head if head != mid else None)
        # Right half forms right subtree
        root.right = self.sortedListToBST(mid.next)

        return root
