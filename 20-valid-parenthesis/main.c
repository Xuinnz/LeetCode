#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Function prototype for your solution
bool isValid(char* s);

int main() {
    // Array of test cases
    char* testCases[] = {
        "()",         // Expected: true
        "()[]{}",     // Expected: true
        "(]",         // Expected: false
        "([)]",       // Expected: false
        "{[]}",       // Expected: true
        "((",         //Expected: false
        "){"           // Expected: false
    };
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    printf("--- Valid Parentheses Test ---\n");

    for (int i = 0; i < numTests; i++) {
        bool result = isValid(testCases[i]);
        printf("Input: \"%s\" \t Result: %s\n", 
                testCases[i], 
                result ? "Valid (true)" : "Invalid (false)");
    }

    return 0;
}
bool isValid(char* s){
    int n = strlen(s);
    char* stack = (char*)malloc(n* sizeof(char));
    if(n == 1){
        return false;
    }
    int stackCount = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[stackCount] = s[i];
            stackCount++;
        } else{
            if(stackCount - 1 < 0) return false;
            if(s[i] == ')' && stack[stackCount - 1] != '(') return false;
            else if(s[i] == ']' && stack[stackCount - 1] != '[') return false;
            else if(s[i] == '}' && stack[stackCount - 1] != '{') return false;
            else stackCount--;
        }
    }
    if(stackCount == 0) return true;
    return false;

}
