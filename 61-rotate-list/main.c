#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode* rotateRight(struct ListNode* head, int k);

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
    // Test Case: [1, 2, 3, 4, 5], k = 2
    // Expected: 4 -> 5 -> 1 -> 2 -> 3 -> NULL
    int arr[] = {1, 2, 3};
    int k = 2000000000;
    struct ListNode* head = createList(arr, 3);

    printf("Original: ");
    printList(head);

    struct ListNode* newHead = rotateRight(head, k);

    printf("Rotated by %d: ", k);
    printList(newHead);

    // Cleanup
    while (newHead) {
        struct ListNode* temp = newHead;
        newHead = newHead->next;
        free(temp);
    }

    return 0;
}
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head) return NULL;
    if(!head -> next) return head;
    int n = 0;
    struct ListNode* current = head;
    while(current){
        n++;
        current = current -> next;
    }
    k = k % n;
    int i;
    for(i = 0; i < k; i++){
        struct ListNode* right = head -> next;
        struct ListNode* left = head;
        while(right -> next){
            right = right -> next;
            left = left -> next;
        }
        left -> next = NULL;
        right -> next = head;
        head = right;
    }
    printf("number of operations: %d\n", i );
    return head;
}