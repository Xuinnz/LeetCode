#include <stdio.h>
#include <limits.h> 
#include <math.h>

//FAILEDDD
//1021 / 1045 testcases passed
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
        if(digits == 10){
        if(x > 0 && x % (int)pow(10, 10) > 7) return 0;
        if(x < 0 && x % (int)pow(10,10) > 8) return 0;
        if(x % (int)pow(10, 9) <= 4)
        if(x % (int)pow(10, 8) <= 6)
        if(x % (int)pow(10, 7) <= 3)
        if(x % (int)pow(10, 6) <= 8)
        if(x % (int)pow(10, 5) <= 4)
        if(x % (int)pow(10, 4) <= 7)
        if(x % (int)pow(10, 3) <= 4)
        if(x % (int)pow(10, 2) <= 1)
        if(x % (int)pow(10, 1) <= 2)
        continue;
        return 0;
        }
        i /= 10;
    }
    int j = 1;
    rev = 0;

    while (digits != 0){
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