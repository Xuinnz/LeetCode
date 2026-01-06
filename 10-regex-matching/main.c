#include <stdio.h>
#include <stdbool.h> // Required for the bool type
#include<string.h>

// Function prototype
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

bool isMatch(char* s, char* p){
    int currentS = 0;
    int currentP = 0;
    int numS = strlen(s);
    int numP = strlen(p);
    while(currentS < numS && currentP < numP){
        if(p[currentP] == '.'){
            if(p[currentP + 1] == '*'){
                if(p[currentP + 2] >= 'a' && p[currentP + 2] <= 'z'){
                    char c = p[currentP + 2];
                    while(c != s[currentS]){
                        currentS++;
                    }
                }
                return true;
            } else{
                currentP++;
                currentS++;
                continue;
            }
        }
        if(p[currentP] >= 'a' && p[currentP] <= 'z'){
            if(p[currentP + 1 == '*']) {
                while(s[currentS] == p[currentP]){
                    currentS++;
                }
                currentP += 2;
                continue;
            }
            else {
                if(s[currentS] != p[currentP]) return false;
                currentS++;
                currentP++;
            }
        }
    }
    return true;

}

//a - required
// a* - zero or more
//. any character