#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode* removeElements(struct ListNode* head, int val);

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
    // Test Case: [1, 2, 6, 3, 4, 5, 6], val = 6
    // Expected Output: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    struct ListNode* head = createList(arr, 7);

    printf("Original List: ");
    printList(head);
    printf("Value to remove: %d\n", val);

    struct ListNode* result = removeElements(head, val);

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
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode dummy = {0, NULL};
    dummy.next = head;
    struct ListNode* curr = &dummy;
    struct ListNode* adv = head;
    while(curr){
        while(adv && (adv == curr || adv -> val == val)){
            adv = adv -> next;
        }
        curr -> next = adv;
        curr = adv;
    }
    return dummy.next;
}
// 1 2 6 3 4 5 6
//           C   A