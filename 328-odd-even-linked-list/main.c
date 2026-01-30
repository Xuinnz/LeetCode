#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototype
struct ListNode* oddEvenList(struct ListNode* head);

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
    // Test Case: [1, 2, 3, 4, 5]
    // Expected Output: 1 -> 3 -> 5 -> 2 -> 4 -> NULL
    int arr[] = {1, 2, 3, 4, 5, 6};
    struct ListNode* head = createList(arr, 6);

    printf("Original List: ");
    printList(head);

    struct ListNode* result = oddEvenList(head);

    printf("Rearranged (Odd-Even): ");
    printList(result);

    // Cleanup memory
    while (result) {
        struct ListNode* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}

struct ListNode* oddEvenList(struct ListNode* head){
    if(!head || !head -> next) return head;
    int length = 1;
    struct ListNode* currOdd = head;
    struct ListNode* evenHead = head -> next;
    struct ListNode* currEven = evenHead;
    struct ListNode* nextOdd;
    struct ListNode* nextEven;
    while(currEven && currOdd){
        if(currOdd -> next) nextOdd = currOdd -> next -> next;
        if(currEven -> next) 
            nextEven = currEven -> next -> next;
        else {
            nextEven = NULL;
        }
        currOdd -> next = nextOdd;
        currEven -> next = nextEven;
        if(!nextOdd) break;
        currOdd = nextOdd;
        currEven = nextEven;
    }
    currOdd -> next = evenHead;
    return head;
}
//   I
//1   2   3   4   5   6 NULL
//hO  hE
//                cO  cE
//                       nEnO
// 1 3 5
// 2 4 6


// 1 | 2 3 4 5
// O   E N