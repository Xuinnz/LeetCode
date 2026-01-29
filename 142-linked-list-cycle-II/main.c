#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode *detectCycle(struct ListNode *head);

// Utility: Create list and return both the head and the node where the cycle starts
struct ListNode* createCycleList(int* arr, int size, int pos, struct ListNode** expectedNode) {
    if (size == 0) return NULL;
    
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    
    struct ListNode* curr = head;
    struct ListNode* target = NULL;
    if (pos == 0) target = head;

    for (int i = 1; i < size; i++) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
        if (i == pos) target = curr;
    }

    if (pos != -1) {
        curr->next = target; // Create the cycle
        *expectedNode = target;
    } else {
        *expectedNode = NULL;
    }
    
    return head;
}

int main() {
    // Test Case: [3, 2, 0, -4], pos = 1 (Cycle begins at node with value 2)
    int arr[] = {3, 2, 0, -4};
    struct ListNode* expectedStart = NULL;
    struct ListNode* head = createCycleList(arr, 4, 1, &expectedStart);

    printf("--- Linked List Cycle II Test ---\n");
    
    struct ListNode* result = detectCycle(head);

    if (result == expectedStart && result != NULL) {
        printf("Success! Cycle detected at node with value: %d\n", result->val);
    } else if (result == NULL && expectedStart == NULL) {
        printf("Success! No cycle detected as expected.\n");
    } else {
        printf("Failed! Pointer mismatch.\n");
    }

    // Note: Do not free memory using a standard loop due to the cycle.
    return 0;
}
struct ListNode *detectCycle(struct ListNode *head){
    if(!head) return NULL;
    if(!head -> next) return NULL;
    if(head -> next == head) return head;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast){
        if(fast) fast = fast -> next;
        if(fast) fast = fast -> next;
        if(slow) slow = slow -> next;
        if(fast == slow) break;
    }
    if(fast == slow){
        fast = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return fast;
    }
    else{
        return NULL;
    }
}