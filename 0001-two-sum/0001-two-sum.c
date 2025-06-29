#include <stdlib.h>

#define TABLE_SIZE 10007  // A prime number for better distribution

// Structure to store value and index
typedef struct {
    int key;
    int value;
} Entry;

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

// Add key-value pair to hash table
void insert(Entry* table, int key, int value) {
    int idx = hash(key);
    while (table[idx].key != INT_MIN && table[idx].key != key) {
        idx = (idx + 1) % TABLE_SIZE;
    }
    table[idx].key = key;
    table[idx].value = value;
}

// Search for key in hash table
int find(Entry* table, int key) {
    int idx = hash(key);
    while (table[idx].key != INT_MIN) {
        if (table[idx].key == key)
            return table[idx].value;
        idx = (idx + 1) % TABLE_SIZE;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int) * 2);

    Entry* table = (Entry*)malloc(sizeof(Entry) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = find(table, complement);
        if (index != -1) {
            result[0] = index;
            result[1] = i;
            free(table);
            return result;
        }
        insert(table, nums[i], i);
    }

    // This should never be reached due to problem constraint (always one solution)
    *returnSize = 0;
    free(result);
    free(table);
    return NULL;
}
