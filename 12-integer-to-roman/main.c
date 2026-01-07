#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// Function prototype - You will implement the logic for this
char* intToRoman(int num);

int main() {
    // Array of test cases to cover standard and subtractive rules
    struct TestCase {
        int input;
        char* expected;
    } tests[] = {
        {3, "III"},           // Basic addition
        {4, "IV"},            // Subtractive (4)
        {9, "IX"},            // Subtractive (9)
        {58, "LVIII"},        // Mixed cases
        {1994, "MCMXCIV"},    // Complex subtractive logic
        {3999, "MMMCMXCIX"}   // Maximum boundary
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("--- Integer to Roman Conversion Tests ---\n\n");

    for (int i = 0; i < numTests; i++) {
        // Note: You should ensure your intToRoman function 
        // returns a string that can be safely printed or freed.
        char* result = intToRoman(tests[i].input);
        
        printf("Input:    %d\n", tests[i].input);
        printf("Result:   %s\n", result);
        printf("Expected: %s\n", tests[i].expected);
        
        // Simple comparison (requires string.h if using strcmp)
        printf("Status:   %s\n", result ? "PROCESSED" : "FAILED");
        printf("----------------------------------------\n");
    }

    return 0;
}

char* intToRoman(int num){
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    char* result = (char*)calloc(16, sizeof(char));
    
    for(int i = 0; i < 13 && num != 0; i++){
        while(num >= values[i]){
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }
    return result;
}