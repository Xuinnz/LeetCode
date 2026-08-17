#include <string.h>

int minimumPushes(char* word){
    int length = strlen(word);
    int quo = length / 8;
    return (4 * quo * (quo + 1)) + ((length - (quo * 8)) * (quo + 1) );
}
