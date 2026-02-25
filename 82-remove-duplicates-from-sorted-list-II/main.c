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
    // Test Case: [1, 2, 3, 3, 4, 4, 5]
    // Expected Output: 1 -> 2 -> 5 -> NULL
    int arr[] = {1, 1, 2, 2, 3};
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
    int headP = 0;
    struct ListNode* currHead = head;
    struct ListNode* adv_start = head;
    struct ListNode* adv_end = head;
    struct ListNode* temp = head -> next;
    if(head -> val != temp -> val){
        headP++;
        adv_start = adv_start -> next;
        adv_end = adv_start;
    }
    while(currHead){
        int match = 0;
        while(adv_start && adv_end && adv_start -> val == adv_end -> val){
            adv_end = adv_end -> next;
            match++;
        }
        if(match > 1 && adv_end == NULL && headP == 0) return NULL;
        if(match > 1){
            currHead -> next = adv_end;
        } else{ 
            currHead = adv_start;
        }
        if(!currHead -> next) break;
        adv_start = currHead -> next;
        adv_end = adv_start;
        if(headP == 0 && match > 1){
            if(adv_start -> next) temp = adv_start -> next;
            if(temp -> val != adv_start -> val){
            head = adv_start ;
            headP++;
            }
        }
    }
    return head;
    // 1 1 2 2 3
    // C   S   E
}   // H S