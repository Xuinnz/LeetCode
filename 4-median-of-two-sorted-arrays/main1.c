#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//FAILEDDDDDD
//400/2000 test cases passed 
//needs refactor

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main() {
    // --- TEST CASE 1 ---
    int a1[] = {1, 2};
    int a2[] = {3, 4};
    int size1 = sizeof(a1) / sizeof(a1[0]);
    int size2 = sizeof(a2) / sizeof(a2[0]);

    printf("Test Case 1:\n");
    printf("Input: [1, 2], [3, 4]\n");
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
        if (nums2Size % 2 != 0) return nums2[nums2Size / 2] / 1.0;
        return (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
    }
    if (nums2Size == 0) {
        if (nums1Size % 2 != 0) return nums1[nums1Size / 2] / 1.0;
        return (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0;
    }
    int totalNum = nums1Size + nums2Size;
    int totalArr[totalNum];
    int k = 0, j = 0;

    for(int i = 0; i < totalNum; i++){
        if(k >= nums1Size){
            totalArr[i] = nums2[j];
            j++;
            continue;
        }
        if(j >= nums2Size){
            totalArr[i] = nums1[k];
            k++;
            continue;
        }
        if(nums1[k] > nums2[j]){
            totalArr[i] = nums2[j];
            j++;
        } else{
            totalArr[i] = nums1[k];
            k++;
        }
    }
    if(totalNum % 2 != 0){
        return (totalArr[totalNum/ 2]);
    } else{ 
        return (totalArr[totalNum / 2 - 1] + totalArr[totalNum / 2]) / 2.0;
    }
}