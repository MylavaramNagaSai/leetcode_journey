class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // Create a dummy node to simplify insertions at the head
        ListNode* dummy = new ListNode(0);
        
        ListNode* curr = head;

        while (curr) {
            ListNode* prev = dummy;
            ListNode* next = curr->next;

            // Find the right place to insert current node
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert current between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            // Move to the next node
            curr = next;
        }

        return dummy->next;
    }
};
