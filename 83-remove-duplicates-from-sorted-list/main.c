#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode* deleteDuplicates(struct ListNode* head);

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
    // Test Case: [1, 1, 2, 3, 3]
    int arr[] = {1, 1, 2, 3, 3};
    struct ListNode* head = createList(arr, 5);

    printf("Original List: ");
    printList(head);

    struct ListNode* result = deleteDuplicates(head);

    printf("Result List:   ");
    printList(result);

    // Cleanup memory
    while (result) {
        struct ListNode* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
        if (!head) return NULL;
        if(!head -> next) return head;
        struct ListNode* currHead = head;
        struct ListNode* adv = head -> next;
        int firstPass = 0;
        while(currHead){
            while(adv != NULL && currHead -> val == adv -> val){
                adv = adv -> next;
            }
            currHead -> next = adv;
            currHead = adv;
            if (adv) adv = adv -> next;
        }
        return head;
    }