#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize);
int compare_strings(const void *a, const void *b);
bool areEqual(int arr1[], int arr2[], int n);

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
    qsort(words, N, sizeof(char *), compare_strings);
    *returnSize = 0;
    int uWordCount = 0; //count of unique words
    int uWord[M / L]; //index of unique words in words[]
    int frequency[M / L]; //frequency of unique words, use frequency[uWord[uWordCount]] to check
    int* isMatch = (int*)malloc(L * M * sizeof(int));
    for(int i = 0; i < N; i++){ 
        frequency[uWordCount] = 1;
        while(i + 1 < N && !strcmp(words[i], words[i + 1])){
            frequency[uWordCount]++;
            i++;
        }
        uWord[uWordCount] = i;
        uWordCount++;
    }
    for(int i = 0; i < M; i++){ //iterate thru the whole
        int currSeen[uWordCount];
        int offset = 0 + i;
        for(int j = 0; j < uWordCount; j ++) currSeen[j] = 0;
        for(int j = i; j < N; j++){ //iterate thru maxWordCount
            if(strncmp(words[j], s + offset, L) == 0){
                currSeen[j]++;
                offset += L;
            }
        }
        if(areEqual(frequency, currSeen, L)){
            isMatch[*returnSize] = i;
            *(returnSize)++;
        }
    }
    //hellofoobar
    //foo|bar
    return isMatch;
}

bool areEqual(int arr1[], int arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
