#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Your function declaration
char* convert(char* s, int numRows);

int main() {
    // Test Case 1
    char* s1 = "PAYPALISHIRING";
    int rows1 = 3;
    char* result1 = convert(s1, rows1);
    printf("Test 1: %s, Rows: %d\nResult:   %s\nExpected: PAHNAPLSIIGYIR\n\n", s1, rows1, result1);
    free(result1); // Clean up heap memory

    // Test Case 2
    char* s2 = "PAYPALISHIRING";
    int rows2 = 4;
    char* result2 = convert(s2, rows2);
    printf("Test 2: %s, Rows: %d\nResult:   %s\nExpected: PINALSIGYAHRPI\n\n", s2, rows2, result2);
    free(result2);

    // Test Case 3: Edge Case (numRows = 1)
    char* s3 = "A";
    int rows3 = 1;
    char* result3 = convert(s3, rows3);
    printf("Test 3: %s, Rows: %d\nResult:   %s\nExpected: A\n\n", s3, rows3, result3);
    free(result3);

    return 0;
}

// --- Leave the logic for you to implement ---
char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows <= 1 || len <= numRows) {
        char* res = (char*)malloc((len + 1) * sizeof(char));
        strcpy(res, s);
        return res;
    }
    int distance = (numRows - 1) * 2;
    int resultIndex = 0;
    int L, R;
    char* result = (char*)malloc((len + 1) * sizeof(char));


    for(int i = 0; i != numRows; i++){
        int row = i % (numRows + (numRows - 2));
        if (row > (numRows - 1)) row = numRows - (row - numRows); 

        if(row == 0 || row == (numRows - 1)){
            for(int j = row; j < len; j = j + (numRows + (numRows - 2))){
                int k = j;
                result[resultIndex] = s[k];
                k = k + distance;
                resultIndex++;
            }
        } else{
            int diff = (numRows - 1) * 2;
            L = diff - (2 * row);
            R = diff - L;
            int k;
            for(int j = row; j < len; j = j + (numRows + (numRows - 2))){
                k = j;
                result[resultIndex] = s[k];
                resultIndex++;
                k = k + L;
                if(k >= len) break;
                result[resultIndex] = s[k];
                resultIndex++;
                k = k + R;
            }
        }

    }
    result[len] = '\0';
    return result;
}

// 3 - 3
// 4 - 5
// 5 - 7
/*
(rows - 1) x 2;
A     I
B   H J
C  G  K
D F   L
E     M

A    K
B   JL
C  I M
D H  N
EG   O
F    P
*/
