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
#include <string.h>
#include <mem.h> //for malloc???
#include "statistics.h"

static void printStats(FILE *dest, const int count, const double theMean, const double stddev);

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s fileName\n", basename(argv[0]));
        return EXIT_FAILURE;
    }
    //Allocating memory for name of the write file. Adding ResultXXX
    // +7 to add Result_
    char fileNamePrefix [] = "Result_";
    int lengthInputString = strlen(argv[1]) + strlen(fileNamePrefix);
    char *fileName = (char*) malloc((sizeof (char)) * lengthInputString);
    fileName = fileNamePrefix;
    strcat(fileName, argv[1]);

    // file handle. Pointer to the file.
    FILE *inFile;
    FILE *outFile;
    if ((inFile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s: Unable to open %s because: %s\n", basename(argv[0]), argv[1], strerror(errno));
        return EXIT_FAILURE;
    }
    if ((outFile = fopen(fileName, "w")) == NULL) {
        fprintf(stderr, "%s: Unable to open %s because: %s\n", basename(argv[0]), outFile, strerror(errno));
        return EXIT_FAILURE;
    }

    double fileValue, sum, sumsq;
    int count = 0;
    while ((fscanf(inFile, "%lf", &fileValue)) != EOF) {
        sum += fileValue;
        sumsq += fileValue*fileValue;
        count++;
    }
    double meanVal = mean(sum, count);
    double ssdevVal = ssdev(sum, sumsq, count);
    //printf("%d values, Mean = %.5lf, Sample Standard Deviation = %.5lf\n", count, meanVal, ssdevVal);
    printStats(stdout, count, meanVal, ssdevVal);
    printStats(outFile, count, meanVal, ssdevVal);

    // closing access to the file.
    fclose(inFile);
    fclose(outFile);
    // freeing memory allocated to the file file name
    free(fileName);

    return (EXIT_SUCCESS);
}

/*prints results to dest file.*/
static void printStats(FILE *dest, const int count, const double theMean, const double stddev) {
    fprintf(dest, "%d values, Mean = %.5lf, Sample Standard Deviation = %.5lf\n", count, theMean, stddev);
}