#include <stdio.h>
#include <stdlib.h>
#include<math.h>

// Function prototype for the LeetCode solution
int threeSumClosest(int* nums, int numsSize, int target);
int compare(const void* a, const void* b);

int main() {
    // Test Case: nums = [-1, 2, 1, -4], target = 1
    // Sorted: [-4, -1, 1, 2]
    // Possible sums: 
    // -4 + -1 + 1 = -4
    // -4 + -1 + 2 = -3
    // -4 + 1 + 2  = -1
    // -1 + 1 + 2  = 2 (Closest to 1)
    
    int nums[] = {-1, 2, 1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 1;

    printf("--- 3Sum Closest Test ---\n");
    printf("Input Array: [-1, 2, 1, -4]\n");
    printf("Target: %d\n", target);

    int result = threeSumClosest(nums, numsSize, target);

    printf("Closest Sum Found: %d\n", result);
    printf("Difference from target: %d\n", abs(result - target));

    return 0;
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), compare);
    int closestSum = nums[0] + nums[1] + nums[2];
     
    for(int i = 0; i < numsSize - 2; i++){
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int j = i + 1;
        int k = numsSize - 1;
        while(j < k){
            int currentSum = nums[i] + nums[j] + nums[k];
            if(abs(target - closestSum) > abs(target - currentSum)) closestSum = currentSum;
            if(nums[i] + nums[j] + nums[k] == target){
                return target;
            }
            else if(nums[i] + nums[j] + nums[k] > target) k--;
            else if(nums[i] + nums[j] + nums[k] < target) j++;
        }
    }
    return closestSum;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}