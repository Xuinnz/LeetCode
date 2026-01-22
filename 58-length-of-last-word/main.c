#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
int lengthOfLastWord(char* s);

int main() {
    // Array of test cases
    struct {
        char* input;
        char* description;
    } tests[] = {
        {"Hello World", "Simple two words"},
        {"   fly me   to   the moon  ", "Many trailing and internal spaces"},
        {"luffy is still joyboy", "Last word at the end"},
        {"a", "Single character"},
        {"        ", "Only spaces"}
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("--- Length of Last Word Test ---\n\n");

    for (int i = 0; i < numTests; i++) {
        int result = lengthOfLastWord(tests[i].input);
        printf("[%s]\n", tests[i].description);
        printf("Input: \"%s\"\n", tests[i].input);
        printf("Length: %d\n\n", result);
    }

    return 0;
}
// Function prototype
int lengthOfLastWord(char* s){
    int n = strlen(s);
    int result = 0;
    while(s[n - 1] == ' '){
        if(n - 1 == 0) return 0;
        n--;
    }
    while(n - 1 > -1 && s[n - 1] != ' '){
        result++;
        n--;
    }
    return result;
}