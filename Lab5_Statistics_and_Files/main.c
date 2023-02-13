/* 
 * File:   main.c
 * Author: bhupi
 *
 * Created on February 12, 2023, 2:37 p.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
/*
 * 
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s fileName\n", basename(argv[0]));
        return EXIT_FAILURE;
    }
    FILE *inFile;
    if(inFile = fopen(argv[1], "r") == NULL){
        fprintf(stderr, "%s: Unable to open %s because: %s\n", basename(argv[0]), argv[1], strerror(errno));
        return EXIT_FAILURE;
    }else {
        printf("Stuff in the file:");
        
    }
    
    fclose(inFile);
    
    return (EXIT_SUCCESS);
}

