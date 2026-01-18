#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype for your solution
struct ListNode* swapPairs(struct ListNode* head);

// Utility: Create a list from an array
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

// Utility: Print the list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Test Case: [1, 2, 3, 4]
    int arr[] = {1, 2, 3};
    struct ListNode* head = createList(arr, 3);

    printf("Original List: ");
    printList(head);

    // Call your solution
    struct ListNode* swappedHead = swapPairs(head);

    printf("Swapped Pairs: ");
    printList(swappedHead);

    // Cleanup memory
    struct ListNode* temp;
    while (swappedHead) {
        temp = swappedHead;          // Save the current node
        swappedHead = swappedHead->next; // Move to the next node before freeing
        free(temp);                  // Now it's safe to free the memory
    }

    return 0;
}

struct ListNode* swapPairs(struct ListNode* head){
    if(!head) return NULL;
    if(!head -> next) return head;
    struct ListNode* left = head;
    struct ListNode* current = head;
    struct ListNode* right = head -> next;
    while(left -> next){
        if(head == left){
            head = left -> next;
        } else {
            current -> next = right;
        }
        left -> next = right -> next;
        right -> next = left;
        current = left;
        if(left -> next) left = left -> next;
        if(right -> next) right = right -> next;
        if(right -> next) right = right -> next; 
        if(right -> next) right = right -> next; 
    }
    return head;
}
// 1LC -> 2R -> 3 -> NULL
// 2R -> 1C -> 3L -> NULL