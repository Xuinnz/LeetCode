#include <stdio.h>

// Function prototype
int firstMissingPositive(int* nums, int numsSize);

int main() {
    // Array of test cases
    struct {
        int nums[30];
        int size;
        char* desc;
    } tests[] = {
        {{-3,9,16,4,5,16,-4,9,26,2,1,19,-1,25,7,22,2,-7,14,2,5,-6,1,17,3,24,-4,17,15},29, "Small gap (expects 3)"},
        {{3, 4, -1, 1}, 4, "Negatives and gaps (expects 2)"},
        {{7, 8, 9, 11, 12}, 5, "No small positives (expects 1)"},
        {{1, 2, 3}, 3, "Perfect sequence (expects 4)"},
        {{1, 1}, 2, "Duplicates (expects 2)"}
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("--- First Missing Positive Test ---\n\n");

    for (int i = 0; i < numTests; i++) {
        // We pass a pointer to the array within the struct
        int result = firstMissingPositive(tests[i].nums, tests[i].size);
        
        printf("[%s]\n", tests[i].desc);
        printf("Input: ");
        for(int j = 0; j < tests[i].size; j++) printf("%d ", tests[i].nums[j]);
        printf("\nResult: %d\n\n", result);
    }

    return 0;
}
// int firstMissingPositive(int* nums, int numsSize){
//     for(int i = 0; i < numsSize; i++){
//         if(nums[i] <= 0 || nums[i] > numsSize){
//             nums[i] = 0;
//             continue;
//         }
//         int val = nums[i];
//         nums[val - 1] = 1;
//     }
//     int i;
//     for(i = 1; i < numsSize; i++){
//         if (nums[i] == 0) return i;
//     }
//     return i + 1;
// }
int firstMissingPositive(int* nums, int numsSize){
    int i = 0;
    while(i < numsSize){
        if(nums[i] == i + 1 || nums[i] > numsSize || nums[i] <= 0 ||nums[nums[i] - 1] == nums[i]){
            i++;
        }
        else{
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }
    for(i = 0; i < numsSize; i++){
        if (nums[i] != i + 1) return i + 1;
    }
    return i + 1;
}
// 3, 4, -1, 1
// temp
//
// 0 0 1 1 0
// 3 4 2 1
// 0 0 0 0 0
// 3 4 5 1
// 