#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototype
int divide(int dividend, int divisor);

int main() {
    // Array of test cases
    struct {
        int dividend;
        int divisor;
        char* description;
    } tests[] = {
        {10, 3, "Standard positive"},
        {7, -3, "Mixed signs"},
        {0, 1, "Zero dividend"},
        {1, 1, "Dividend equals divisor"},
        {INT_MIN, -1, "Overflow Case (Result > INT_MAX)"},
        {INT_MIN, 1, "Minimum Integer Case"},
        {2147483647, 2, "Maximum Integer Case"}
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("--- Divide Two Integers Test ---\n");
    printf("Range: [%d to %d]\n\n", INT_MIN, INT_MAX);

    for (int i = 0; i < numTests; i++) {
        int result = divide(tests[i].dividend, tests[i].divisor);
        printf("[%s]\n", tests[i].description);
        printf("%d / %d = %d\n\n", tests[i].dividend, tests[i].divisor, result);
    }

    return 0;
}

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    int result = 0;
    bool isNegative = (dividend < 0) ^ (divisor < 0);
    if(dividend > 0) dividend = -dividend;
    if(divisor > 0) divisor = -divisor;

    while (dividend <= divisor){
        int remainder = divisor;
        int i = -1;
        while(remainder >= -1073741824 && dividend <= (remainder << 1)){
            remainder <<= 1;
            i <<= 1;
        }
        dividend -= remainder;
        result += i;
    }
    return isNegative ? -result : result;
}