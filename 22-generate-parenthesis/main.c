#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParentheses(int n, int* returnSize);
void backtracking(int n, int index, int open, int close, char* path, char** result, int* returnSize);

int main() {
    // Test Case: n = 3
    // Expected Output: ["((()))","(()())","(())()","()(())","()()()"]
    int n = 3;
    int returnSize = 0;

    printf("--- Generate Parentheses Test ---\n");
    printf("Input n: %d\n", n);

    // Call your implementation
    char** results = generateParentheses(n, &returnSize);

    if (results == NULL || returnSize == 0) {
        printf("No combinations generated.\n");
    } else {
        printf("Found %d valid combinations:\n", returnSize);
        printf("[\n");
        for (int i = 0; i < returnSize; i++) {
            printf("  \"%s\"%s\n", results[i], (i == returnSize - 1) ? "" : ",");
        }
        printf("]\n");

        // --- Memory Cleanup ---
        // Each string was malloced/duplicated individually
        for (int i = 0; i < returnSize; i++) {
            free(results[i]);
        }
        // The array of pointers itself must also be freed
        free(results);
        printf("\nMemory successfully cleaned up.\n");
    }

    return 0;
}
char** generateParentheses(int n, int* returnSize){
    *returnSize = 0;
    char path[2 * n + 1];
    int size;
    if(n == 1) size = 1; else if(n == 2) size = 2; else if(n == 3) size = 5; else if(n == 4) size = 14; 
    else if(n == 5) size = 42; else if(n == 6) size = 132; else if(n == 7) size = 429; else if(n == 8) size = 1430;
    char** result = (char**)malloc(size * sizeof(char*));

    backtracking(n, 0, 0, 0, path, result, returnSize);
    return result;
}

void backtracking(int n, int index, int open, int close, char* path, char** result, int* returnSize){
    if(index == n * 2){
        path[index] = '\0';
        result[*returnSize] = strdup(path);
        (*returnSize)++;
        return;
    }
    if(open < n) {
        path[index] = '(';
        backtracking(n, index + 1, open + 1, close, path, result, returnSize);
    }
    if(close < open){
        path[index] = ')';
        backtracking(n, index + 1, open, close + 1, path, result, returnSize);
    }
}   