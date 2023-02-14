/* 
 * File:   main.c
 * Author: bhupi
 *
 * Created on February 12, 2023, 2:37 p.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <errno.h>
#include "statistics.h"
/*
 * 
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s fileName\n", basename(argv[0]));
        return EXIT_FAILURE;
    }
    // file handle. Pointer to the file.
    FILE *inFile;
    if((inFile = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "%s: Unable to open %s because: %s\n", basename(argv[0]), argv[1], strerror(errno));
        return EXIT_FAILURE;
    }else {
        double fileValue, sum, sumsq;
        int count=0;
        while( (fscanf(inFile, "%lf", &fileValue)) != EOF ){
            sum += fileValue;
            sumsq += pow(fileValue,2);
            count++;
        }
        double meanVal = mean(sum, count);
        double ssdevVal = ssdev(sum, sumsq, count);
        printf("%d values, Mean = %.5lf, Sample Standard Deviation = %.5lf\n", count, meanVal, ssdevVal);
     }
    // closing access to the file.
    fclose(inFile);
    
    return (EXIT_SUCCESS);
}

