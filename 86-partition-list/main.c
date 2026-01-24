#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode* partition(struct ListNode* head, int x);

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
    // Test Case: [1, 4, 3, 2, 5, 2], x = 3
    // Expected Output: 1 -> 2 -> 2 -> 4 -> 3 -> 5 -> NULL
    int arr[] = {1, 4, 3, 0, 5, 2};
    int x = 2;
    struct ListNode* head = createList(arr, 6);

    printf("Original List: ");
    printList(head);
    printf("Partition x: %d\n", x);

    struct ListNode* result = partition(head, x);

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

struct ListNode* partition(struct ListNode* head, int x){
    if(!head) return NULL;
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* currDummy = &dummy;
    struct ListNode* curr = head;
    struct ListNode* adv = head -> next;
    while(curr && curr -> val >= x){ //if first element is >=
        currDummy -> next = curr;
        currDummy = currDummy -> next;
        curr = curr -> next;
        head = curr;
        currDummy -> next = NULL;
    }
    if(!head) return dummy.next;
    while(curr -> next){
        adv = curr -> next;
        while(adv && adv -> val >= x){
            currDummy -> next = adv;
            currDummy = currDummy -> next;
            adv = adv -> next;
            currDummy -> next = NULL;
        }
        curr -> next = adv;
        if(!curr -> next) break;
        curr = curr -> next;
        adv = curr -> next;
    }
    curr -> next = dummy.next;
    return head;
}   
// 1 2 3
//   C   A
//D -> 4 -> 3 -> 5