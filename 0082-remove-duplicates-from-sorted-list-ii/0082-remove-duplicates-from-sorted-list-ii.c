struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        // Check if this node is a start of duplicates
        if (curr->next != NULL && curr->val == curr->next->val) {
            int dupVal = curr->val;
            // Skip all nodes with the same value
            while (curr != NULL && curr->val == dupVal) {
                struct ListNode* temp = curr;
                curr = curr->next;
                free(temp);  // free memory if needed
            }
            prev->next = curr; // skip all duplicates
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}
