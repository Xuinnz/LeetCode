#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode* reverseList(struct ListNode* head);

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
    if (!head) {
        printf("Empty List\n");
        return;
    }
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Test Case: [1, 2, 3, 4, 5]
    // Expected Output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
    int arr[] = {1, 2, 3, 4, 5};
    struct ListNode* head = createList(arr, 5);

    printf("Original List: ");
    printList(head);

    struct ListNode* reversedHead = reverseList(head);

    printf("Reversed List: ");
    printList(reversedHead);

    // Cleanup memory
    while (reversedHead) {
        struct ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        free(temp);
    }

    return 0;
}

struct ListNode* reverseList(struct ListNode* head){
    if(!head) return NULL;
    if(!head -> next) return head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* adv = NULL;

    while(curr){
        adv = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = adv;
    }
    return prev;
}