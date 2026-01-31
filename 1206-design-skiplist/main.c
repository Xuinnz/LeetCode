#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct definition (You will implement this)
typedef struct Skiplist Skiplist;
typedef struct Node Node;

// Function prototypes
Skiplist* skiplistCreate();
Node* createNode(int val, int level)
bool skiplistSearch(Skiplist* obj, int target);
void skiplistAdd(Skiplist* obj, int num);
bool skiplistErase(Skiplist* obj, int num);
void skiplistFree(Skiplist* obj);

int main() {
    printf("--- Design Skiplist Simulation ---\n\n");

    Skiplist* obj = skiplistCreate();

    // 1. Add some elements
    printf("Adding: 1, 2, 3\n");
    skiplistAdd(obj, 1);
    skiplistAdd(obj, 2);
    skiplistAdd(obj, 3);

    // 2. Search for elements
    printf("Search 0: %s (Expect: false)\n", skiplistSearch(obj, 0) ? "true" : "false");
    
    // 3. Add more elements
    printf("Adding: 4\n");
    skiplistAdd(obj, 4);

    // 4. Search again
    printf("Search 1: %s (Expect: true)\n", skiplistSearch(obj, 1) ? "true" : "false");

    // 5. Erase an element
    printf("Erasing 0: %s (Expect: false)\n", skiplistErase(obj, 0) ? "true" : "false");
    printf("Erasing 1: %s (Expect: true)\n", skiplistErase(obj, 1) ? "true" : "false");

    // 6. Search for the erased element
    printf("Search 1 after erase: %s (Expect: false)\n", skiplistSearch(obj, 1) ? "true" : "false");

    skiplistFree(obj);
    printf("\nSkiplist memory freed.\n");

    return 0;
}

typedef struct {
    int level;
    int count;
    struct Node *head;
} Skiplist;

typedef struct Node {
    int val;
    struct Node* next[];
} Node;

Node* createNode(int val, int level){
    Node *n = malloc(sizeof(Node) + (level * sizeof(Node*)));
    n -> val = val;
    for(int i = 0; i < level; i++){
        n -> next[i] = NULL;
    }
    return n;
}
Skiplist* skiplistCreate() {
    Skiplist* obj = (Skiplist*)malloc(sizeof(Skiplist));
    obj->level = 0;
    obj->count = 0;
    // The head must be created with the max level capacity
    obj->head = createNode(-1, 32); 
    return obj;
}


bool skiplistSearch(Skiplist* obj, int target) {
    Node* curr = obj -> head;
    for(int i = 32 - 1; i >= 0; i--){
        while(curr -> next[i] && curr -> next[i] -> val < target){
            curr = curr -> next[i];
        }
    }
    curr = curr -> next[0];
    return curr && curr -> val == target;
}

void skiplistAdd(Skiplist* obj, int num) {
    Node* update[32];
    Node* curr = obj -> head;

    for(int i = 32 - 1; i >= 0; i--){
        while(curr -> next[i] && curr -> next[i] -> val < num){
            curr = curr -> next[i];
        }
        update[i] = curr;
    }
    int lvl = 1;
    while(lvl < 32 && (rand() % 100 < 50)) lvl++;

    Node* newNode = createNode(num, lvl);
    for(int i = 0; i < lvl; i++){
        newNode -> next[i] = update[i] -> next [i];
        update[i] -> next[i] = newNode;
    }
    
}

bool skiplistErase(Skiplist* obj, int num) {
    Node* update[32];
    Node* curr = obj -> head;
    for(int i = 32 - 1; i >= 0; i--){
        while(curr -> next[i] && curr -> next[i] -> val < num){
            curr = curr -> next[i];
        }
        update[i] = curr;
    }

    curr = curr -> next[0];
    if(!curr || curr -> val != num){
        return false;
    }

    for(int i = 0; i < 32; i++){
        if(update[i] -> next[i] != curr){
            break;
        }
        update[i] -> next[i] = curr -> next[i];
    }

    free(curr);
    return true;
    
}

void skiplistFree(Skiplist* obj) {
    if (!obj) return;
    Node* curr = obj -> head;
    Node* nextNode;

    while(curr != NULL){
        nextNode = curr -> next[0];
        free(curr);
        curr = nextNode;
    }
    free(obj);
}