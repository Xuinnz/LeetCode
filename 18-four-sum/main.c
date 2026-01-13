#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes);
int compare(const void* a, const void* b);

int main() {
    // Test Case: [1, 0, -1, 0, -2, 2], target = 0
    int nums[] = {1000000, 1000000, 1000000, 1000000};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    int returnSize = 0;
    int* returnColumnSizes = NULL;

    printf("--- 4Sum Test ---\n");
    printf("Input: [1000000, 1000000, 1000000, 1000000], Target: %d\n", target);

    // Call the solution function
    int** result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);

    printf("Found %d quadruplets:\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d, %d]\n", result[i][0], result[i][1], result[i][2], result[i][3]);
    }

    // --- Memory Cleanup ---
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), compare);
    int capacity = 1;
    for (int i = 1; i <= 4; i++) {
        capacity = capacity * (numsSize - i + 1) / i;
    }
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int l = numsSize - 1; l > i; l--){
            if (l < numsSize - 1 && nums[l] == nums[l + 1]) continue;
            int j = i + 1;
            int k = l - 1;
            while(j < k){
            if((long)nums[i] + nums[j] + nums[k] + nums[l] == target){
                result[*returnSize] = (int*)malloc(4 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[*returnSize][2] = nums[k];
                result[*returnSize][3] = nums[l];
                j++;
                k--;
                (*returnColumnSizes)[*returnSize] = 4;
                (*returnSize)++;
                while (j < k && nums[j] == nums[j - 1]) j++; 
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
            else if((long)nums[i] + nums[j] + nums[k] + nums[l] > target) k--;
            else if((long)nums[i] + nums[j] + nums[k] + nums[l] < target) j++;
            }
        }
        

    }
    return result;
}

int compare(const void* a, const void* b){
    return (*(int*) a - *(int*) b);
}
