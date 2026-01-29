#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode* insertionSortList(struct ListNode* head);

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
    // Test Case: [4, 2, 1, 3]
    // Expected Output: 1 -> 2 -> 3 -> 4 -> NULL
    int arr[] = {4, 2, 1, 3};
    struct ListNode* head = createList(arr, 4);

    printf("Original List: ");
    printList(head);

    struct ListNode* sortedHead = insertionSortList(head);

    printf("Sorted List:   ");
    printList(sortedHead);

    // Cleanup
    while (sortedHead) {
        struct ListNode* temp = sortedHead;
        sortedHead = sortedHead->next;
        free(temp);
    }

    return 0;
}
struct ListNode* insertionSortList(struct ListNode* head){
    if(!head || !head -> next) return head;
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* curr = head;
    while(curr){
        struct ListNode* adv = curr -> next;
        struct ListNode* sorted = &dummy;
        if(!sorted -> next){
            sorted -> next = curr;
            curr -> next = NULL;
            curr = adv;
            continue;
        } 
        struct ListNode* connect = sorted -> next;
        while(connect && connect -> val < curr -> val){
            sorted = sorted -> next;
            connect = connect -> next;
        }
        sorted -> next = curr;
        curr -> next = connect;
        curr = adv;
    }
    return dummy.next;
}

// | 4 2 1 3
// 4 | 2 1 3
// P   C A