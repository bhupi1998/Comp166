/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: bhupi
 *
 * Created on February 16, 2023, 5:29 p.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "arraySearch.h"

/*
 * 
 */
int main(int argc, char** argv) {
    if(argc != 3){
        fprintf(stderr,"Usage: %s numberFileName nNumbers\n", basename(argv[0]));
        return EXIT_FAILURE;
    }    
    // pointer to requested binary file
    FILE *binaryFile;
    // ensuring binary file can be opened
    if( (binaryFile = fopen(argv[1],"rb")) == NULL){
        fprintf(stderr,"%s: Unable to open %s because: %s\n", basename(argv[0]), argv[1], strerror(errno));
        return EXIT_FAILURE;
    }
    int fileIntegerSize;
    if((sscanf(argv[2], "%d", &fileIntegerSize)) != 1){
        fprintf(stderr,"%s: Unable to convert \"%s\" into an integer value.", basename(argv[0]), argv[2] );
        return EXIT_FAILURE;
    }
    // allocating memory to the heap
    int *dataIntArray = (int*)malloc(fileIntegerSize*sizeof(int));
    if((fread(dataIntArray, sizeof(int), fileIntegerSize, binaryFile))!= fileIntegerSize){
        fprintf(stderr,"%s: Unable to read %d numbers from file \"%s\"\n",basename(argv[0]), fileIntegerSize, argv[1]);
        return EXIT_FAILURE;
    }
    int valToFind;
    while(1){
        printf("Enter the integer value to find ('q' to quit) : ");
        if(scanf("%d", &valToFind) == 0){
            char exitVal[1];
            scanf("%c", exitVal[0]);
            if( exitVal == 'q' || exitVal == 'Q'){
                printf("Oke Bye\n");
                return EXIT_SUCCESS;
            } else{
                printf("Invalid Input\n");
            }
        }
        int valIndex = linearSearch (valToFind, dataIntArray, fileIntegerSize);
        if(valIndex == -1){
            printf("%d was not found\n", valToFind);
        }else {
            printf("%d was found at position %d\n", valToFind, valIndex);
        }
    }
    // closing file
    fclose(binaryFile);
    // freeing memory from the heap
    free(dataIntArray);
    return (EXIT_SUCCESS);
}

