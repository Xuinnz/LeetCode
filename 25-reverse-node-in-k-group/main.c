#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype for your solution
struct ListNode* reverseKGroup(struct ListNode* head, int k);
struct ListNode* reverse(struct ListNode* head, struct ListNode* index);

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
    // Test Case: [1, 2, 3, 4, 5], k = 2
    // Expected Output: 2 -> 1 -> 4 -> 3 -> 5 -> NULL
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    struct ListNode* head = createList(arr, n);

    printf("Original List: ");
    printList(head);
    printf("k = %d\n", k);

    // Call your solution
    struct ListNode* result = reverseKGroup(head, k);

    printf("Modified List: ");
    printList(result);

    // Cleanup
    struct ListNode* temp;
    while (result) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* index = head;
    struct ListNode* prevHead = head;
    struct ListNode* currHead = NULL;
    struct ListNode* nextHead = NULL;
    int length = 0;
    int passes = 0;
    
    while(index){
        length++;
        if(k == length){
            nextHead = index->next;
            if (passes == 0) currHead = head;
            else currHead = prevHead->next;
            struct ListNode* newGroupHead = reverse(currHead, index);
            if (passes == 0) head = newGroupHead; 
            else prevHead->next = newGroupHead;
            currHead->next = nextHead;
            prevHead = currHead;
            index = nextHead;
            length = 0;
            passes++;
        }
        else 
        index = index -> next;
    }
    if(length > 0 && length < k){

        currHead -> next = nextHead;
    }
    return head;
    
}

struct ListNode* reverse(struct ListNode* head, struct ListNode* index){
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    while(prev != index){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    //returns new head
}



// 1CP -> NULL 2N -> 3 -> 4