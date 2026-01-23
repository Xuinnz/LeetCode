#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize);
int compare(const void* a, const void* b);

int main() {
    // Test Case: s = "barfoothefoobarman", words = ["foo","bar"]
    char* s = "barfoothefoobarman";
    char* words[] = {"foo", "bar"};
    int wordsSize = 2;
    int returnSize;

    printf("--- Substring with Concatenation ---\n");
    printf("Haystack: %s\n", s);
    printf("Words: [\"%s\", \"%s\"]\n", words[0], words[1]);

    // Call your solution
    int* result = findSubstring(s, words, wordsSize, &returnSize);

    // Print results
    printf("Indices found: ");
    if (returnSize == 0) {
        printf("None");
    } else {
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", result[i]);
        }
    }
    printf("\n");

    // Cleanup
    free(result);

    return 0;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize){
    int L = strlen(words[0]);
    int N = wordsSize;
    int M = strlen(s);
    qsort(words, n, sizeof(char *), compare_strings);
    int uWordCount = 0; //count of unique words
    int uWord[]; //index of unique words in words[]
    int frequency[]; //frequency of unique words, use frequency[uWord[uWordCount]] to check
    for(int i = 0; i < N; i++){ 
        frequency[uWordCount] = 1;
        while(i + 1 < N && !strcmp(nums[i], nums[i + 1])){
            frequency[uWordCount]++;
            i++;
        }
        uWord[uWordCount] = i;
        uWordCount++;
    }
    for(int i = 0; i < M; i++){
        int currSeen[uWord];
        for(int j = 0; j < uWordCount; j ++) currSeen[j] = 0;
        for(int j = i; j < N; j++){

        }
    }





}



int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
