class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: move `prev` to the node before `left`
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // Step 2: reverse sublist from left to right
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* tmp = curr->next;
            curr->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }

        return dummy.next;
    }
};
