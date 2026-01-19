#include <stdio.h>

// Function prototype:
// Returns the number of elements not equal to val
int removeElement(int* nums, int numsSize, int val);

int main() {
    // Test Case: nums = [0,1,2,2,3,0,4,2], val = 2
    // Expected Output: k = 5, nums = [0,1,3,0,4,_,_,_]
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 2;

    printf("--- Remove Element Test ---\n");
    printf("Target to remove: %d\n", val);
    printf("Original array: ");
    for (int i = 0; i < numsSize; i++) printf("%d ", nums[i]);
    printf("\n\n");

    // Call your implementation
    int k = removeElement(nums, numsSize, val);

    // Output results
    printf("New Length (k): %d\n", k);
    printf("Modified Array (first k elements): ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

int removeElement(int* nums, int numsSize, int val){
    int length = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[length] = nums[i];
            length++;
        }
    }
    return length;
}
// [0,1,2,2,3,0,4,2] ,val = 2;
    //8 
// [0,1,3,2,2,0,4,2]     
