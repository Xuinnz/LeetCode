#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d", node->val);
        if (node->next != NULL) printf(" -> ");
        node = node->next;
    }
    printf("\n");
}

int main() {
    // --- Create List 1: [2, 4, 3] (represents 342) ---
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // --- Create List 2: [5, 6, 4] (represents 465) ---
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    printf("List 1: "); printList(l1);
    printf("List 2: "); printList(l2);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: "); printList(result);
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head;
    struct ListNode* output = &head;
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry != 0){
        output -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
        output = output -> next;
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        int sum = val1 + val2 + carry;
        carry = 0;
        if (sum >= 10){
            carry = 1;
            sum %= 10;
        }
        output -> val = sum;
        output -> next = NULL;
        if(l1 != NULL) l1 = l1 -> next;
        if(l2 != NULL) l2 = l2 -> next;
    }

    return head.next;
}