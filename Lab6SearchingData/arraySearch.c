
#include "arraySearch.h"

int linearSearch (const int value, const int numbers[], const int nNumbers){
    for(int i = 0; i < nNumbers; i++){
        if(value == numbers[i]){
            return i;
        }
    }
    // nothing found, returning -1
    return -1;
}