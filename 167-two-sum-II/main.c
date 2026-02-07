/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int start = 0;
    int end = numbersSize - 1;
    int* returnArr = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;
    while (start < end){
        if (target == (numbers[start] + numbers[end])){
            *returnSize = 2;
            returnArr[0] = start + 1;
            returnArr[1] = end + 1;
            return returnArr;
        }
        else if(target > numbers[start] + numbers[end]){
            start++;
        }
        else {
            end--;
        }
    }
    return returnArr;
}