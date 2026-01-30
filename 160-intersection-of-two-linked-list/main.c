#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);

// Utility: Create a basic list from array
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

int main() {
    // 1. Create common part: [8, 4, 5]
    int commonArr[] = {8, 4, 5};
    struct ListNode* common = createList(commonArr, 3);

    // 2. Create list A prefix: [4, 1] and connect to common
    int aArr[] = {4, 1};
    struct ListNode* headA = createList(aArr, 2);
    headA->next->next = common; // A: 4 -> 1 -> 8 -> 4 -> 5

    // 3. Create list B prefix: [5, 6, 1] and connect to common
    int bArr[] = {5, 6, 1};
    struct ListNode* headB = createList(bArr, 3);
    headB->next->next->next = common; // B: 5 -> 6 -> 1 -> 8 -> 4 -> 5

    printf("--- Intersection of Two Linked Lists ---\n");
    struct ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection) {
        printf("Intersected at node with value: %d\n", intersection->val);
        printf("Memory Address: %p\n", (void*)intersection);
    } else {
        printf("No intersection found.\n");
    }

    // Cleanup: Be careful not to double-free the common part!
    // (In a real app, you'd free headA's unique nodes, then headB's, then common).
    return 0;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
    if(headA == headB) return headA;
    if(!headA || !headB || (!headA -> next && !headB -> next)) return NULL;
    int lengthA = 0, lengthB = 0;
    struct ListNode* currA = headA;
    struct ListNode* currB = headB;
    while(currA){
        lengthA++;
        currA = currA -> next;
    }
    while(currB){
        lengthB++;
        currB = currB -> next;
    }
    int diff;
    currA = headA;
    currB = headB;
    if(lengthA > lengthB){
        diff = lengthA - lengthB;
        while(diff){
            currA = currA -> next;
            diff--;
        }
    } else{
        diff = lengthB - lengthA;
        while(diff){
            currB = currB -> next;
            diff--;
        }
    }
    while(currA && currB){
        if(currA == currB) return currA; 
        currA = currA -> next;
        currB = currB -> next;
    }
    return NULL;
}