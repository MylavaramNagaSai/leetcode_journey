class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create new nodes interleaved with original nodes
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Set random pointers of the new nodes
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate the two lists
        curr = head;
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;

        while (curr) {
            copyCurr->next = curr->next;
            curr->next = curr->next->next;

            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return dummy->next;
    }
};
