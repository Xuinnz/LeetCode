#include <stdio.h>
#include <stdbool.h> 
#include<string.h>

//passed
//recursive, fix it to dynamic programming
bool isMatch(char* s, char* p);

int main() {
    // Array of test cases
    struct TestCase {
        char* s;
        char* p;
        bool expected;
    } tests[] = {
        {"aa", "a", false},      // Simple mismatch
        {"aa", "a*", true},      // Kleene star matching multiple 'a's
        {"ab", ".*", true},      // Dot-Star: Matches any string
        {"aab", "c*a*b", true},  // Zero 'c's, two 'a's, one 'b'
        {"mississippi", "mis*is*p*.", false}, // Complex sequence mismatch
        {"ab", ".*c", false}     // Pattern requires a 'c' at the end
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("--- Regular Expression Matching Tests ---\n\n");

    for (int i = 0; i < numTests; i++) {
        bool result = isMatch(tests[i].s, tests[i].p);
        printf("S: \"%s\" | P: \"%s\"\n", tests[i].s, tests[i].p);
        printf("Result: %s (Expected: %s)\n", 
                result ? "true" : "false", 
                tests[i].expected ? "true" : "false");
        printf("----------------------------------------\n");
    }

    return 0;
}
bool isMatch(char* s, char* p) {
    if(*p == '\0') return *s == '\0';

    bool first_match = (*s != '\0' && (*p == *s || *p == '.'));

    if(*(p + 1) == '*'){
        return (isMatch(s, p + 2) || (first_match && isMatch(s + 1, p)));
    }
    else{
        return first_match && isMatch(s + 1, p + 1);
    }
}