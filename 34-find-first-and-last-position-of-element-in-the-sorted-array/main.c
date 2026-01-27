#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main() {
    // Test Case: [5, 7, 7, 8, 8, 10], target = 8
    // Expected: [3, 4]
    int nums[] = {5,7,7,8,8,10};
    int n = 6;
    int target = 8;
    int returnSize;

    printf("--- Find First and Last Position ---\n");
    printf("Array: [5, 7, 7, 8, 8, 10], Target: %d\n", target);

    int* result = searchRange(nums, n, target, &returnSize);

    if (result[0] == -1) {
        printf("Target not found.\n");
    } else {
        printf("Range: [%d, %d]\n", result[0], result[1]);
    }

    // Always free memory allocated by the function
    free(result);

    return 0;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int right = numsSize - 1;
    int left = 0;
    int* arr = (int*)malloc(2 * sizeof(int));
    arr[0] = -1;
    arr[1] = -1;
    if(numsSize == 0 ) return arr;
    while (right >= left || (arr[0] > -1 && arr[1] == -1) || (arr[0] == -1 && arr[1] > -1)){
        if(nums[left] != target || arr[0] > -1) left++;
        else arr[0] = left;

        if(nums[right] != target || arr[1] > -1) right--;
        else arr[1] = right;
    }
    return arr;
}