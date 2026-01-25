#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode* reverseBetween(struct ListNode* head, int left, int right);

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
    // Test Case: [1, 2, 3, 4, 5], left = 2, right = 4
    // Expected Output: 1 -> 4 -> 3 -> 2 -> 5 -> NULL
    int arr[] = {1, 2, 3, 4, 5};
    int left = 3, right = 4;
    struct ListNode* head = createList(arr, 5);

    printf("Original List: ");
    printList(head);
    printf("Reverse range: %d to %d\n", left, right);

    struct ListNode* result = reverseBetween(head, left, right);

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
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(!head) return NULL;
    if(!head -> next) return head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* adv = NULL;
    struct ListNode* tail = NULL;
    struct ListNode* tempHead = head;
    int i = 0;
    int pass = 0;
    int Head = 1;
    while(i < left){
        if(i + 1 == left) prev = curr;
        curr = curr -> next;
        i++;
    }
    if(i == 1) Head = 0;
    if(i != 1){ //if with head
        while(tempHead -> next != prev)tempHead = tempHead -> next;
    }

    while(curr && i < right){
        if(pass == 0){
            tail = prev;
            pass++;
        }
        adv = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = adv;
        i++;
    }
    if(!Head){
        head = prev;
    }else{
        tempHead -> next = prev;
    }
    tail -> next = curr;
    return head;
    // 1 > 2 < 3 < 4 < 5  NULL  L = 2 R = 4
    //     P   C
    // T
    //i =  1
}