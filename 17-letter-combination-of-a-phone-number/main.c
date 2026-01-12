#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize);
void backtrack(char* digits, int index, char* path, char** result, int* returnSize);

int main() {
    // Test Case: Standard keypad input "23"
    // Expected Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    char* testInput = "23";
    int returnSize = 0;

    printf("--- Letter Combinations of a Phone Number ---\n");
    printf("Input digits: \"%s\"\n\n", testInput);

    // Call your implementation
    char** results = letterCombinations(testInput, &returnSize);

    if (results == NULL || returnSize == 0) {
        printf("Result: []\n");
    } else {
        printf("Found %d combinations:\n", returnSize);
        printf("[");
        for (int i = 0; i < returnSize; i++) {
            printf("\"%s\"%s", results[i], (i == returnSize - 1) ? "" : ", ");
        }
        printf("]\n");

        // --- Memory Cleanup ---
        // You must free each individual string before freeing the outer array
        for (int i = 0; i < returnSize; i++) {
            free(results[i]);
        }
        free(results);
        printf("\nMemory successfully freed.\n");
    }

    return 0;
}

const char* mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char** letterCombinations(char* digits, int* returnSize){
    int count = strlen(digits);
    int total = 1;
    *returnSize = 0;
    for(int i = 0; i < count; i++){
        if(digits[i] == '7' || digits[i] == '9'){
            total *= 4;
        }
        else total *= 3;
    }
    char** result = (char**)malloc(total * sizeof(char*));
    char path[count + 1];
    backtrack(digits, 0, path, result, returnSize);
    return result;
    

}

void backtrack(char* digits, int index, char* path, char** result, int* returnSize){
    if(index == strlen(digits)){
        path[index] = '\0';
        result[*returnSize] = strdup(path);
        (*returnSize)++;
        return;
    }
    int digit = digits[index] - '0';
    const char* letters = mapping[digit];

    for(int i = 0; i < strlen(letters); i++){
        path[index] = letters[i];
        backtrack(digits, index + 1, path, result, returnSize);
    }
}