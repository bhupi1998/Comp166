#include "pointerLab.h"

/* Swap the two values pointed at by x and y*/
void swap (WORD *x, WORD *y){
    WORD tempVal = *y;
    *y=*x;
    *x=tempVal;
}

/* Print all of the values in a 1-D array where the array size is N
*  and WORD_FORMAT has been #define'd*/
void printVector (const WORD *vec, const int N){
    for(int i = 0; i<N; i++){
        printf(WORD_FORMAT,*(vec+i));
        printf(" ");
    }
    printf("\n");
}

/* Print all of the values in a 1-D array one byte at a time where the 
 * array size is N.
 * Prints an extra space after each word*/
void printBytes (const WORD *vec, const int N){
    for(int i=0; i < N; i++){
        char *val = vec + i;
        for(int k=0; k<sizeof(WORD);k++){
            // don't understand why i need to cast it as an unsigned char
            // when val is defined as a char pointer.
            printf("%hhu ", *((unsigned char*)val+k));
        }
        printf(" ");
    }
    printf("\n");
}

/* Print all of the values in a 1-D array one byte at a time in reverse
 * byte order for each word where the array size is N.
 * Prints an extra space after each word */
void printBytesReverseEndian (const WORD *vec, const int N){
    for(int i=0; i < N; i++){
        char *val = vec + i;
        for(int k=sizeof(WORD)-1; k>=0;k--){
            // don't understand why i need to cast it as an unsigned char
            // when val is defined as a char pointer.
            printf("%hhu ", *((unsigned char*)val+k));
        }
        printf(" ");
    }
    printf("\n");
}