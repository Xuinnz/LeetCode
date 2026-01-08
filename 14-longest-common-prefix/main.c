#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype - You will implement the logic for this
char* longestCommonPrefix(char** strs, int strsSize);

int main() {
    // Array of test cases
    struct TestCase {
        char* input[5];
        int size;
        char* expected;
    } tests[] = {
        {{"flower", "flow", "flight"}, 3, "fl"},
        {{"dog", "racecar", "car"}, 3, ""},
        {{"interspecies", "interstellar", "interstate"}, 3, "inters"},
        {{"throne", "throne"}, 2, "throne"},
        {{"apple"}, 1, "apple"}
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("--- Longest Common Prefix Tests ---\n\n");

    for (int i = 0; i < numTests; i++) {
        // longestCommonPrefix should return a heap-allocated string 
        // or a static string that can be printed.
        char* result = longestCommonPrefix(tests[i].input, tests[i].size);
        
        printf("Test %d:\n", i + 1);
        printf("Input:    [");
        for(int j = 0; j < tests[i].size; j++) {
            printf("\"%s\"%s", tests[i].input[j], j == tests[i].size - 1 ? "" : ", ");
        }
        printf("]\n");
        printf("Result:   \"%s\"\n", result);
        printf("Expected: \"%s\"\n", tests[i].expected);
        printf("Status:   %s\n", strcmp(result, tests[i].expected) == 0 ? "PASSED" : "FAILED");
        printf("----------------------------------------\n");
        
        // If your function uses malloc, remember to free(result) here.
    }

    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize){
    int maxLen = strlen(strs[0]);
    char* result = (char*)calloc(maxLen + 1, sizeof(char));
    int j = 0;

    for(int i = 0; i < maxLen; i++){
        char curr = strs[0][i];
        for(j = 1; j < strsSize; j++){
            if(curr != strs[j][i]){
                break;
            }
        }
        if(j != strsSize) return result;
        result[i] = curr;
    }
    return result;
}