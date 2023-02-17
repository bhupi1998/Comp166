
#include "arraySearch.h"

int linearSearch (const int value, const int numbers[], const int nNumbers){
    for(int i = 0; i < nNumbers; i++){
        if(value == numbers[i]){
            return i;
        }
    }
    return -1;
}