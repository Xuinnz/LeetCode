#include <stdio.h>
#include <limits.h> // Essential for INT_MAX and INT_MIN
#include <math.h>

// PASSED
int reverse(int x);

int main() {
    // Test Cases
    int testCases[] = {12345, -12345, 1244, 12512, 1534236469};
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    printf("--- Reverse Integer Tests ---\n\n");

    for (int i = 0; i < numTests; i++) {
        int input = testCases[i];
        int result = reverse(input);
        
        printf("Input:  %d\n", input);
        printf("Result: %d\n", result);
        
        // Edge case check for the user
        if (input != 0 && result == 0 && input % 10 != 0) {
            printf("(Note: Overflow occurred and was handled)\n");
        }
        printf("---------------------------\n");
    }

    return 0;
}

int reverse(int x) {
    int rev = 0;

    int digits = 0;
    int i = x;
    while(i != 0){
        digits++;
        i /= 10;
    }
    int j = 1;
    rev = 0;

    while (digits != 0){
        if(rev > INT_MAX / 10 || (rev == INT_MAX && (x % 10) > 7)) return 0;
        if(rev < INT_MIN / 10 || (rev == INT_MIN && (x % 10) < -8)) return 0;
        rev = (rev * 10) + (x % 10);
        x /= 10;
        digits--;
        j++;
    }
    return rev;
}

/*

INT_MAX: 2,147,483,647
INT_MIN:-2,147,483,648

7 463 847 412
8 463 847 412

1 111 111 119

*/