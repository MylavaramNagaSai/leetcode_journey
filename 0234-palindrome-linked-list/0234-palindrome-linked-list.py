# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True

        # 1. Find the middle (slow will be at mid)
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # 2. Reverse the second half
        prev = None
        while slow:
            tmp = slow.next
            slow.next = prev
            prev = slow
            slow = tmp

        # 3. Compare first half and reversed second half
        left, right = head, prev
        while right:  # only need to check the second half
            if left.val != right.val:
                return False
            left = left.next
            right = right.next

        return True
