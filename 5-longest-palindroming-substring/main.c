#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s);

int main() {
    // Test Cases
    char* testCases[] = {
        "babab",    // Should return "bab" or "aba"
        "cbbd",     // Should return "bb"
        "bb",        // Should return "a"
        "ac",       // Should return "a" or "c"
        "racecar",  // Should return "racecar"
        "aaaa"      // Should return "aaaa"
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    printf("--- Longest Palindromic Substring Tests ---\n\n");

    for (int i = 0; i < numTests; i++) {
        char* input = testCases[i];
        char* result = longestPalindrome(input);

        if (result != NULL) {
            printf("Input:  %s\n", input);
            printf("Result: %s\n", result);
            printf("---------------------------\n");
            
        } else {
            printf("Input:  %s\nResult: NULL\n", input);
        }
    }

    return 0;
}
char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) == 0) return "";
    if (strlen(s) == 1) return s;

    int curr = 0;
    int window = 1;
    int start = curr;
    int currCount = 1, maxCount = 1;

    while(curr < strlen(s)){
        //even
        if(s[curr] == s[curr + 1]){
            currCount++;
            while((curr - window) >= 0 && (curr + window) < strlen(s) && s[curr - window] == s[curr + window + 1]){
                currCount += 2;
                if(curr - window < 0){
                    break;
                }
                window++;
            }
            if(currCount >= maxCount){
            maxCount = currCount;
            start = curr - window + 1;
        }
        window = 1;
        currCount = 1;
        //odd
        }if ((curr - window) >= 0 && s[curr - 1] == s[curr + 1]){
            while((curr - window) >= 0 && (curr + window) < strlen(s) && s[curr - window] == s[curr + window]){
                currCount += 2;
                if(curr - window < 0) break;
                window++;
            }
            if(currCount >= maxCount){
            maxCount = currCount;
            start = curr - window + 1;
        }
        }
        currCount = 1;
        curr++;
        window = 1;
        }
        
    char* result = (char*)malloc(maxCount + 1);
    strncpy(result, s + start, maxCount);
    result[maxCount] = '\0';
    return result; 
}