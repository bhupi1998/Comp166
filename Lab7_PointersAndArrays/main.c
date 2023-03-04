/* 
 * File:   main.c
 * Author: Bhupinder Singh
 * Lab 7 Pointer and arrays
 *
 * Created on March 4, 2023, 2:17 p.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pointerLab.h"

/*
 * 
 */
int main(int argc, char** argv) {
    WORD valueArray[N_NUMS];
    for(int i = 0; i<N_NUMS; i++){
        // type casting to ensure array is incremented by the desired value
        // is it even necessary?
        valueArray[i]= START_VAL+(WORD)i;
    }
    printf("Original vector:\n");
    printVector(valueArray, N_NUMS);
    for(int i = 0; i<(N_NUMS-1); i += 2){
        swap(valueArray+i,valueArray+i+1);
    }
    printf("Adjacent words swapped:\n");
    printVector(valueArray, N_NUMS);
    
    for(int i = 0; i<(N_NUMS-1); i += 2){
        // name of array is address of first array element
        swap(&valueArray[i],&valueArray[i+1]);
    }
    printf("Words swapped back:\n");
    printVector(valueArray, N_NUMS);
    printf("Data Bytes:\n");
    printBytes(valueArray, N_NUMS);
    
    printf("Word bytes with endian reversal:\n");
    printBytesReverseEndian(valueArray, N_NUMS);
    return (EXIT_SUCCESS);
}

