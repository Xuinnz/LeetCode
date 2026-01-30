#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
void deleteNode(struct ListNode* node);

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

// Utility: Print list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Test Case: [4, 5, 1, 9], Target Node to delete: 5
    // Expected: 4 -> 1 -> 9 -> NULL
    int arr[] = {4, 5, 1, 9};
    struct ListNode* head = createList(arr, 4);

    // Let's grab the pointer for the node with value 5
    struct ListNode* target = head->next; 

    printf("Original List: ");
    printList(head);
    printf("Deleting node with value: %d\n", target->val);

    deleteNode(target);

    printf("Result List:   ");
    printList(head);

    // Cleanup
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
void deleteNode(struct ListNode* node){
    struct ListNode* adv = node;
    adv = adv -> next;
    adv = adv -> next;
    node -> val = node -> next -> val;
    node -> next = adv;
}