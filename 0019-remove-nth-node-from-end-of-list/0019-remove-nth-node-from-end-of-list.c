/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create a dummy node to simplify edge cases (like removing the head)
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // Move fast pointer n+1 steps ahead to maintain a gap
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete);

    return dummy.next;
}
