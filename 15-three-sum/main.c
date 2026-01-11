#include <stdio.h>
#include <stdlib.h>

// Function prototype for the 3Sum logic
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
int compare(const void* a, const void* b);

int main() {
    // Test Case: Standard array with duplicates and zeros
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    // These variables will be updated by your function
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    printf("--- 3Sum Problem Test ---\n");
    printf("Input Array: [-1, 0, 1, 2, -1, -4]\n\n");

    // Calling the function
    int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("Triplets Found: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d%s", result[i][j], j == returnColumnSizes[i] - 1 ? "" : ", ");
        }
        printf("]\n");
    }

    // --- CRITICAL: Memory Cleanup (Thesis/Optimization Focus) ---
    for (int i = 0; i < returnSize; i++) {
        free(result[i]); // Free each individual triplet
    }
    free(result);             // Free the array of pointers
    free(returnColumnSizes); // Free the array of sizes

    printf("\nMemory cleared successfully.\n");
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), compare);
    int capacity = 20000;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0){
            break;
        }
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int j = i + 1;
        int k = numsSize - 1;
        while(j < k){
            if(nums[i] + nums[j] + nums[k] == 0){
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[*returnSize][2] = nums[k];
                j++;
                k--;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (j < k && nums[j] == nums[j - 1]) j++; // Skip identical left values
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
            else if(nums[i] + nums[j] + nums[k] > 0) k--;
            else if(nums[i] + nums[j] + nums[k] < 0) j++;
            }
        }
    return result;
    }

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}