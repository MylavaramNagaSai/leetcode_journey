// LeetCode provides the struct ListNode definition – do NOT redefine it.

struct ListNode* swapPairs(struct ListNode* head) {
    // Create a dummy node to simplify head swaps
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (prev->next && prev->next->next) {
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;

        // Swap the pair
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // Move to the next pair
        prev = first;
    }

    return dummy.next;
}
