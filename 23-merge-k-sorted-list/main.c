#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* merge(struct ListNode* list1, struct ListNode* list2);

// Function prototype for your solution
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);

// Utility: Create a linked list from an array
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

// Utility: Print a linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Test Case: [[1,4,5],[1,3,4],[2,6]]
    int a1[] = {1, 4, 5};
    int a2[] = {1, 3, 4};
    int a3[] = {2, 6};

    int k = 3;
    // Allocate array of pointers for k lists
    struct ListNode** lists = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    
    lists[0] = createList(a1, 3);
    lists[1] = createList(a2, 3);
    lists[2] = createList(a3, 2);

    printf("--- Merging %d Sorted Lists ---\n", k);
    for (int i = 0; i < k; i++) {
        printf("List %d: ", i);
        printList(lists[i]);
    }

    // Call your solution
    struct ListNode* result = mergeKLists(lists, k);

    printf("\nFinal Merged List: ");
    printList(result);

    // --- Cleanup ---
    struct ListNode* temp;
    while (result) {
        temp = result;
        result = result->next;
        free(temp);
    }
    free(lists);

    return 0;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0) return NULL;
    int interval = 1;
    while(interval < listsSize){
        for(int i = 0; i + interval < listsSize; i = i + interval * 2){
            lists[i] = merge(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }
    return lists[0];
} 

struct ListNode* merge(struct ListNode* list1, struct ListNode* list2){
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    while(list1 && list2){
        if(list1 -> val <= list2 -> val){
            tail -> next = list1;
            list1 = list1 -> next;
        }
        else{
            tail -> next = list2;
            list2 = list2 -> next;
        }
        tail = tail -> next;
    }
    if(list1) tail -> next = list1;
    else tail -> next = list2;
    return dummy.next;
}