struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int length = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    tail->next = head; // make it circular

    k %= length;
    int stepsToNewTail = length - k;

    struct ListNode* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
