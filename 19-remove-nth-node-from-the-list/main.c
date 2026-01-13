#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype for your solution
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

// Utility function to create a linked list from an array
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}

// Utility function to print the list
void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    // Test Case: [1, 2, 3, 4, 5], n = 2
    // Expected: 1 -> 2 -> 3 -> 5 -> NULL
    int arr[] = {1, 2, 3, 4, 5};
    int n = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    struct ListNode* head = createList(arr, size);

    printf("Original List: ");
    printList(head);
    printf("Target N from end: %d\n", n);

    // Call your implementation
    head = removeNthFromEnd(head, n);

    printf("Modified List: ");
    printList(head);

    // --- Cleanup ---
    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* left = head;
    struct ListNode* current = head;
    struct ListNode* right = head;
    int i = 0;
    int j = 0;
    if (right -> next == NULL){
        free(head);
        return NULL;
    }
    while(right != NULL){
        if(i < n - 1) i++;
        else current = current -> next;
        if(j < n + 1)j++;
        else left = left -> next;
        right = right -> next;
    }
    if(left -> next == current)head = head -> next;
    else left -> next = current;
    return head;
}