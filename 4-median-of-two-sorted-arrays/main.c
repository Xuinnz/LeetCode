#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//FAILEDDDDDD
//400/2000 test cases passed 
//needs refactor

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main() {
    // --- TEST CASE 1 ---
    int a1[] = {1, 3, 4, 10, 12};
    int a2[] = {2, 5, 7};
    int size1 = sizeof(a1) / sizeof(a1[0]);
    int size2 = sizeof(a2) / sizeof(a2[0]);

    printf("Test Case 1:\n");
    printf("Input: [1, 3, 4, 10, 12], [2, 5, 7]\n");
    printf("Result: %f\n\n", findMedianSortedArrays(a1, size1, a2, size2));

    //FAILEDDDD
    int b1[] = {0,0,0,0,0};
    int b2[] = {-1,0,0,0,0,0,1};
    int bSize1 = sizeof(b1) / sizeof(b1[0]);
    int bSize2 = sizeof(b2) / sizeof(b2[0]);
    
    printf("Test Case 2:\n");
    printf("Input: [1, 2], [-1, 3]\n");
    printf("Result: %f\n\n", findMedianSortedArrays(b1, bSize1, b2, bSize2));

    return 0;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size == 0 && nums2Size == 0) return 0.0;
    if (nums1Size == 0) {
        if (nums2Size % 2 != 0) return nums2[nums2Size / 2];
        return (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
    }
    if (nums2Size == 0) {
        if (nums1Size % 2 != 0) return nums1[nums1Size / 2];
        return (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0;
    }

    int median1 = 0, median2 = 0;
    double finalmedian;
    bool odd = ((nums1Size + nums2Size) % 2 != 0);
    int start1 = 0, start2 = 0, end1 = nums1Size - 1, end2 = nums2Size - 1;
    if((nums1Size + nums2Size) % 2 != 0) odd = true;
    
    for(int i = 1; i <= nums1Size + nums2Size; i *= 2){
        median1 = start1 + (end1 - start1 + 1) / 2;
        median2 = start2 + (end2 - start2 + 1) / 2;

        if(nums1[median1] <= nums2[median2]){
            start1 = median1;
            end2 = median2;
        } else {
            end1 = median1;
            start2 = median2;
        } 
    }

    median1 = (start1 + end1) / 2;
    median2 = (start2 + end2) / 2;

    if(odd){
        printf("%d %d", median1, median2);
        if (nums1[median1] >= nums2[median2]) return nums1[median1];
        else return nums2[median2];
    }
    else {
        printf("%d %d", median1, median2);
        return (nums1[median1] + nums2[median2]) / 2.0;
    }
}