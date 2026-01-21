#include <stdio.h>

// Function prototype
int searchInsert(int* nums, int numsSize, int target);

int main() {
    // Test cases
    int nums[] = {1, 3, 5, 6};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    struct {
        int target;
        char* desc;
    } cases[] = {
        {5, "Target exists in middle"},
        {2, "Target missing (should be index 1)"},
        {7, "Target missing (should be at end)"},
        {0, "Target missing (should be at start)"}
    };

    printf("--- Search Insert Position ---\n");
    printf("Array: [1, 3, 5, 6]\n\n");

    for (int i = 0; i < 4; i++) {
        int result = searchInsert(nums, n, cases[i].target);
        printf("Target %d (%s) -> Index: %d\n", cases[i].target, cases[i].desc, result);
    }

    return 0;
}

int searchInsert(int* nums, int numsSize, int target){
    int start = 0;
    int end = numsSize - 1;
    int current = (start + end) / 2;
    if(numsSize == 1){
        if(nums[0] < target) return 1;
        else return 0;
    }
    if(target < nums[0]) return 0;

    for(int i = 1; i < numsSize + 1; i *= 2){
        if(nums[current] > target){
            end = current;
            current = (start + end) / 2;
        }
        else if(nums[current] < target){
            start = current;
            current = (start + end) / 2;
        }
        else{
            return current;
        }
    }
    return current + 1;
}

//[1, 3, 5, 6] target = 7
//    S  C  E
