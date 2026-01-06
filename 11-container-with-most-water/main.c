#include <stdio.h>

// Function prototype - You will implement this logic
int maxArea(int* height, int heightSize);

int main() {
    // Array of test cases
    struct TestCase {
        int heights[10];
        int size;
        int expected;
    } tests[] = {
        {{1, 8, 6, 2, 5, 4, 8, 3, 7}, 9, 49}, // Standard case
        {{1, 1}, 2, 1},                      // Minimum size case
        {{4, 3, 2, 1, 4}, 5, 16},            // Equal heights at ends
        {{1, 2, 1}, 3, 2}                    // Peak in the middle
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("--- Container With Most Water Tests ---\n\n");

    for (int i = 0; i < numTests; i++) {
        int result = maxArea(tests[i].heights, tests[i].size);
        
        printf("Test %d:\n", i + 1);
        printf("Heights: [");
        for(int j = 0; j < tests[i].size; j++) {
            printf("%d%s", tests[i].heights[j], j == tests[i].size - 1 ? "" : ", ");
        }
        printf("]\n");
        printf("Result: %d | Expected: %d\n", result, tests[i].expected);
        printf("Status: %s\n", result == tests[i].expected ? "PASSED" : "FAILED");
        printf("---------------------------------------\n");
    }

    return 0;
}

int maxArea(int* height, int heightSize) {
    int area = 0;
    int n = heightSize - 1;
    int m = 0;
    for(int i = 0; i < heightSize; i++){
        int lessHeight = 0;
        if(*(height + m) > *(height + n)){
            lessHeight = *(height + n);
            if(area < (lessHeight * (n - m))) area = (lessHeight * (n - m));
            n--;
        } else{
            lessHeight = *(height + m);
            if(area < (lessHeight * (n - m))) area = (lessHeight * (n - m));
            m++;
        }
        
    }
    return area;
}

//area = <pillar height x n 