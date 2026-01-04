#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Your function declaration
int myAtoi(char* s);

int main() {
    // Test Cases
    char* testCases[] = {
        "42",                // Basic positive
        "   -42",            // Leading whitespace and sign
        "1337c0d3",          // Digits followed by words
        "1493 with words",               // Sign in the wrong place (should return 0)
        "words and 987",     // Leading words (should return 0)
        "-91283472332",      // Underflow (should return INT_MIN)
        "2147483648"         // Overflow (should return INT_MAX)
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    printf("--- String to Integer (atoi) Tests ---\n\n");

    for (int i = 0; i < numTests; i++) {
        char* input = testCases[i];
        int result = myAtoi(input);
        
        printf("Input:  \"%s\"\n", input);
        printf("Result: %d\n", result);
        printf("---------------------------\n");
    }

    return 0;
}

int myAtoi(char* s) {
    int res = 0;
    int current = 0;

    // 1. Skip whitespace
    while(s[current] == ' '){
        current++;
    }
    // 2. Handle sign (+ or -)
    bool isNegative = false;
    if(s[current] == '-'){
        isNegative = true;
        current++;
    } else if(s[current] == '+'){
        current++;
    }
    
    // 3. Convert digits until a non-digit is found
    while(s[current] >= '0' && s[current] <= '9'){
        int digit = s[current] - '0';
        // 4. Handle overflow/underflow (clamping)
        if(res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)){
            return isNegative ? INT_MIN : INT_MAX;
        }
        res = res * 10 + digit;
        current++;
    }
    return isNegative ? (0 - res) : res;
}