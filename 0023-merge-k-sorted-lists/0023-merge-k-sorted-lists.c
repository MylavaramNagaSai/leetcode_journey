#include <stdlib.h>

// ✅ No struct ListNode definition needed — LeetCode provides it

// Helper: heapify-down (min-heap)
void heapifyDown(struct ListNode** heap, int heapSize, int index) {
    int smallest = index;
    int left = 2 * index + 1, right = 2 * index + 2;

    if (left < heapSize && heap[left]->val < heap[smallest]->val)
        smallest = left;
    if (right < heapSize && heap[right]->val < heap[smallest]->val)
        smallest = right;

    if (smallest != index) {
        struct ListNode* temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;
        heapifyDown(heap, heapSize, smallest);
    }
}

// Helper: heapify-up (for insertion)
void heapifyUp(struct ListNode** heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index]->val < heap[parent]->val) {
            struct ListNode* temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            index = parent;
        } else {
            break;
        }
    }
}

// Main function
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    struct ListNode** heap = (struct ListNode**)malloc(listsSize * sizeof(struct ListNode*));
    int heapSize = 0;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i]) {
            heap[heapSize++] = lists[i];
            heapifyUp(heap, heapSize - 1);
        }
    }

    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (heapSize > 0) {
        struct ListNode* minNode = heap[0];
        tail->next = minNode;
        tail = tail->next;

        if (minNode->next) {
            heap[0] = minNode->next;
        } else {
            heap[0] = heap[--heapSize];
        }
        heapifyDown(heap, heapSize, 0);
    }

    free(heap);
    return dummy.next;
}
