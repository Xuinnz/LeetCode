#include <stdio.h>

// Function prototype: 
// Returns the number of unique elements (k)
int removeDuplicates(int* nums, int numsSize);

int main() {
    // Test Case: [0,0,1,1,1,2,2,3,3,4]
    int nums[] = {1, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original Array Size: %d\n", numsSize);
    printf("Original Elements: ");
    for (int i = 0; i < numsSize; i++) printf("%d ", nums[i]);
    printf("\n\n");

    // Call your implementation
    int k = removeDuplicates(nums, numsSize);

    // Results
    printf("New Length (k): %d\n", k);
    printf("Modified Array (first k elements): ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
int removeDuplicates(int* nums, int numsSize){
    int length = 0;
    for (int i = 0; i < numsSize; i++){
        int j = 0; //num of shifts need
        while((j + i + 1) < numsSize && nums[i] == nums[j + i + 1] ){
            j++;
        }
        for(int k = i + j + 1; k < numsSize; k++){
            nums[k - j] = nums[k]; //shifting
        }
        numsSize -= j;
        length++;

    }
    return length;
}

// Test Case: [0,0,1,1,1,2,2,3,3,4]