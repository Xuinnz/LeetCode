#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x);


int main(){
    int testCases[] = {
        121,
        -121,
        10,
        123454321,
        101011
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    printf("--- Palindrome Number Tests ---\n\n");
    for(int i = 0; i < numTests; i++){
        printf("Input: %d", testCases[i]);
        printf("\nOutput: %s", isPalindrome(testCases[i]) ? "true" : "false");
        printf("\n\n");
    }
}

bool isPalindrome(int x){
    int number = x;
    int rev = 0;
    if(x < 0) return false;
    if(x >= 0 && x <= 9) return true;
    while(x != 0){
        if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && (x % 10) > 7)) return false;
        rev = (rev * 10) + (x % 10);
        x = x / 10;
    }
    if(number == rev) return true;
    else return false;

}