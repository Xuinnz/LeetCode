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
    int numS = strlen(s);
    int numP = strlen(p);

    bool dp[numS + 1][numP + 1];
    memset(dp, false, sizeof(dp));

    dp[0][0] = true;
    for(int j = 2; j <= numP; j++){
        if(p[j - 1] == '*'){
            dp[0][j] == dp[0][j - 2];
        }
    }

    for(int i = 1; i <= numS; i++){
        for(int j = 1; j <= numP; j++){
            if(p[numP] == s[numS] || p[j - 1] == '.'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(p[j - 1] == '*'){
                dp[i][j] = dp[i][j - 2];

                if(p[j - 2] == s[i - 1] || p[j - 2] == '.'){
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }
    return dp[numS][numP];
}