#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
bool hasCycle(struct ListNode *head);

// Utility: Create list and optionally create a cycle
struct ListNode* createCycleList(int* arr, int size, int pos) {
    if (size == 0) return NULL;
    
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    
    struct ListNode* curr = head;
    struct ListNode* cycleNode = NULL;
    
    if (pos == 0) cycleNode = head;

    for (int i = 1; i < size; i++) {
        curr->next = malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
        if (i == pos) cycleNode = curr;
    }

    // Connect the tail to the cycleNode to create the loop
    if (pos != -1) {
        curr->next = cycleNode;
    }
    
    return head;
}

int main() {
    // Test Case: [3, 2, 0, -4], pos = 1 (Cycle points back to value '2')
    int arr[] = {3, 2, 0, -4};
    int n = 4;
    int pos = 1; 

    struct ListNode* head = createCycleList(arr, n, pos);

    printf("--- Linked List Cycle Test ---\n");
    printf("List created with cycle at index: %d\n", pos);

    if (hasCycle(head)) {
        printf("Result: Cycle detected! (Correct)\n");
    } else {
        printf("Result: No cycle detected. (Incorrect)\n");
    }

    // NOTE: Do not attempt to free a circular list using standard loops!
    // It will result in an infinite loop. 
    return 0;
}
bool hasCycle(struct ListNode *head){
    if(!head) return NULL;
    if(!head -> next) return false;
    if(head -> next == head) return true;
    struct ListNode* slow = head;
    struct ListNode* fast = slow -> next;
    while(fast -> next){
        if(slow == fast) return true;
        if(fast -> next) fast = fast -> next;
        if(fast -> next) fast = fast -> next;
        if(slow -> next) slow = slow -> next;
    }
    return false;
}
// 3 2 0 4
//       FS