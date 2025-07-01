class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes for the two partitions
        ListNode lessDummy(0), moreDummy(0);
        ListNode* less = &lessDummy;
        ListNode* more = &moreDummy;

        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                more->next = head;
                more = more->next;
            }
            head = head->next;
        }

        // Final connections
        more->next = nullptr;          // End the "more" list
        less->next = moreDummy.next;   // Join the two lists

        return lessDummy.next;
    }
};
