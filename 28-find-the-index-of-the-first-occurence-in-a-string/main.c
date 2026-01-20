#include <stdio.h>
#include <string.h>

// Function prototype
int strStr(char* haystack, char* needle);

int main() {
    // Array of test cases
    struct TestCase {
        char* haystack;
        char* needle;
    };

    struct TestCase tests[] = {
        {"sadbutsad", "sad"},   // Expected: 0
        {"leetcode", "leeto"},  // Expected: -1
        {"hello", "ll"},        // Expected: 2
        {"aaaaa", "bba"},       // Expected: -1
        {"mississippi", "issi"} // Expected: 4
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("--- Index of First Occurrence Test ---\n");

    for (int i = 0; i < numTests; i++) {
        int result = strStr(tests[i].haystack, tests[i].needle);
        printf("Haystack: \"%s\", Needle: \"%s\" -> Index: %d\n", 
                tests[i].haystack, tests[i].needle, result);
    }

    return 0;
}
int strStr(char* haystack, char* needle){
    int n = strlen(haystack); //bigger
    int m = strlen(needle); //smaller
    if (m == 0) return 0;
    if(m > n) return -1;
    m--;
    for(int i = m; i < n; i++){
        int depth = 0;
        while((i - depth) >= 0 && (m - depth) >= 0 && haystack[i - depth] == needle[m - depth]){
            depth++;
        }
        if(depth - 1 == m){
            return i - m;
        }
    }
    return -1;
}
//Haystack: "hello", Needle: "ll"
//            ll
//Haystack: "mississippi", Needle: "issi"
//           sissi