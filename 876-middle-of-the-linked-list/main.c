#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode* middleNode(struct ListNode* head);

// Utility: Create list from array
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}

int main() {
    // Test Case 1: [1, 2, 3, 4, 5] (Odd length)
    // Expected Output: Node with value 3
    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode* head1 = createList(arr1, 5);
    struct ListNode* mid1 = middleNode(head1);
    printf("Odd Length Mid:  %d\n", mid1 ? mid1->val : -1);

    // Test Case 2: [1, 2, 3, 4, 5, 6] (Even length)
    // Expected Output: Node with value 4 (the second middle)
    int arr2[] = {1, 2, 3, 4, 5, 6};
    struct ListNode* head2 = createList(arr2, 6);
    struct ListNode* mid2 = middleNode(head2);
    printf("Even Length Mid: %d\n", mid2 ? mid2->val : -1);

    // Cleanup (simplified)
    // In a real app, you'd free both head1 and head2 chains.
    return 0;
}
struct ListNode* middleNode(struct ListNode* head){
    if(!head || !head -> next) return head;
    if(!head -> next -> next) return head -> next;
    struct ListNode* adv = head -> next -> next;
    head = head -> next;
    while(adv && adv -> next){
        if(adv -> next) adv = adv -> next -> next;
        head = head -> next;
    }
    return head;
}