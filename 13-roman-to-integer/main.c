#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// Function prototype - You will implement the logic for this
int romanToInt(char* s);

int main() {
    // Array of test cases to cover standard and subtractive rules
    struct TestCase {
        int expected;
        char* input;
    } tests[] = {
        {3, "III"},           // Basic addition
        {4, "IV"},            // Subtractive (4)
        {9, "IX"},            // Subtractive (9)
        {58, "LVIII"},        // Mixed cases
        {1994, "MCMXCIV"},    // Complex subtractive logic
        {3999, "MMMCMXCIX"}   // Maximum boundary
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("--- Roman to Integer Conversion Tests ---\n\n");

    for (int i = 0; i < numTests; i++) {
        int result = romanToInt(tests[i].input);
        
        printf("Input:    %s\n", tests[i].input);
        printf("Result:   %d\n", result);
        printf("Expected: %d\n", tests[i].expected);
        
        // Simple comparison (requires string.h if using strcmp)
        printf("Status:   %s\n", result ? "PROCESSED" : "FAILED");
        printf("----------------------------------------\n");
    }

    return 0;
}

int romanToInt(char* s){
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int result = 0;
    int sIndex = 0;
    
    for(int i = 0; i < 13; i++){
        int sLen = strlen(symbols[i]);
        while(strncmp(s + sIndex, symbols[i], sLen) == 0){
            result += values[i];
            sIndex += sLen;
        }
    }
    return result;
}