#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype for your solution
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);

// Utility function to create a linked list from an array
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

// Utility function to print the list
void printList(struct ListNode* head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    struct ListNode* curr = head;
    while (curr) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    // Test Case: List1 = [1, 2, 4], List2 = [1, 3, 4]
    // Expected Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> NULL
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    
    struct ListNode* list1 = createList(arr1, 3);
    struct ListNode* list2 = createList(arr2, 3);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Call your implementation
    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    // --- Cleanup ---
    // Only need to free mergedList because it contains all nodes from 1 and 2
    struct ListNode* temp;
    while (mergedList) {
        temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode sortedList;
    struct ListNode* tail = &sortedList;

    while(list1 && list2){
        if(list1 -> val >= list2 -> val){
            tail -> next = list2;
            list2 = list2 -> next;
        } else{
            tail -> next = list1;
            list1 = list1 -> next; 
        }
        tail = tail -> next;
    }
    if(list1 || list2){
        while(list1){
            tail -> next = list1;
            list1 = list1 -> next;
            tail = tail -> next;
        }
        while(list2){
            tail -> next = list2;
            list2 = list2 -> next;
            tail = tail -> next;
        }
    }
    return sortedList.next;
}