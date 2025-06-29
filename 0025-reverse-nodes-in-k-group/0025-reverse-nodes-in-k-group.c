// Do NOT redefine struct ListNode — LeetCode provides it

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k <= 1 || head == NULL) return head;

    // Count total number of nodes
    struct ListNode* node = head;
    int length = 0;
    while (node) {
        length++;
        node = node->next;
    }

    // Dummy node to simplify head reversal
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prevGroup = &dummy;

    while (length >= k) {
        struct ListNode* curr = prevGroup->next;
        struct ListNode* next = curr->next;

        // Reverse k nodes
        for (int i = 1; i < k; i++) {
            curr->next = next->next;
            next->next = prevGroup->next;
            prevGroup->next = next;
            next = curr->next;
        }

        prevGroup = curr;
        length -= k;
    }

    return dummy.next;
}
