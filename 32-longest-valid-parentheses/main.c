#include <stdio.h>
#include <string.h>

// Function prototype
int longestValidParentheses(char* s);

int main() {
    // Array of test cases
    struct {
        char* input;
        char* description;
    } tests[] = {
        {"(()", "Partial match at end"},
        {")()())", "Interrupted valid sequence"},
        {"()(())", "Fully valid nested sequence"},
        {"", "Empty string"},
        {"(((", "No closing brackets"},
        {")()(", "Single valid pair in middle"}
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("--- Longest Valid Parentheses Test ---\n\n");

    for (int i = 0; i < numTests; i++) {
        int result = longestValidParentheses(tests[i].input);
        printf("[%s]\n", tests[i].description);
        printf("Input:  \"%s\"\n", tests[i].input);
        printf("Result: %d\n\n", result);
    }

    return 0;
}
int longestValidParentheses(char* s){
    int left = 0;
    int right = 0;
    int maxRight = 0;
    int maxLeft = 0;
    int result = 0;
    int n = strlen(s);
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '(') left++;
        else right++;
        if(right > left){
            right = 0;
            left = 0;
        }
        if(left == right && right > maxRight) maxRight = right;
    }
    right = 0;
    left = 0;
    for(int i = n - 1; i != -1 ; i--){
        if(s[i] == '(') left++;
        else right++;
        if(right < left){
            right = 0;
            left = 0;
        }
        if(left == right && left > maxLeft) maxLeft = left;
    }
    result = (maxLeft > maxRight) ? maxLeft : maxRight; 

    return result * 2;
}