#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char* s);
int main() {
    // Array of test cases
    char* testStrings[] = {
        "abcabcbb", // Example 1: Should be 3
        "bbbbb",    // Example 2: Should be 1
        "pwwkew",   // Example 3: Should be 3
        "",         // Edge Case: Empty string
        " ",        // Edge Case: Single space
        "au"        // Edge Case: Two unique
    };

    int numTests = sizeof(testStrings) / sizeof(testStrings[0]);

    for (int i = 0; i < numTests; i++) {
        int result = lengthOfLongestSubstring(testStrings[i]);
        printf("Input: \"%s\" \t| Result: %d\n", testStrings[i], result);
    }

    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    int longestLength = 0;
    int currentLength = 0;
    int index = 0;
    int head = 0;
    char subset[n + 1]; 

    while(s[head] != '\0'){
        bool flag = false;

        for(int j = 0; j < currentLength; j++){
            if (subset[j] == s[head + index]){
                flag = true;
                break;
            }
        }
        if(flag || s[head + index] == '\0'){
            if(currentLength > longestLength){
                longestLength = currentLength;
            }
            currentLength = 0;            
            head++;
            index = 0;
        } else {
            subset[currentLength] = s[head + index];
            currentLength++;
            index++;
        }
    }
    return longestLength;
}