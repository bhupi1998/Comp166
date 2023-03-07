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
    if (argc != 3) {
        fprintf(stderr, "Usage: %s numberFileName nNumbers\n", basename(argv[0]));
        return EXIT_FAILURE;
    }
    // pointer to requested binary file
    FILE *binaryFile;
    // ensuring binary file can be opened
    if ((binaryFile = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s: Unable to open %s because: %s\n", basename(argv[0]), argv[1], strerror(errno));
        return EXIT_FAILURE;
    }
    int fileIntegerSize;
    if ((sscanf(argv[2], "%d", &fileIntegerSize)) != 1) {
        fprintf(stderr, "%s: Unable to convert \"%s\" into an integer value.", basename(argv[0]), argv[2]);
        return EXIT_FAILURE;
    }
    // allocating memory to the heap
    int *dataIntArray = (int*) malloc(fileIntegerSize * sizeof (int));
    if ((fread(dataIntArray, sizeof (int), fileIntegerSize, binaryFile)) != fileIntegerSize) {
        fprintf(stderr, "%s: Unable to read %d numbers from file \"%s\"\n", basename(argv[0]), fileIntegerSize, argv[1]);
        return EXIT_FAILURE;
    }
    // closing file since everything has been saved in an array.
    fclose(binaryFile);

    int valToFind;
    // see solution below
    char userInput[13];
    while (1) {
        printf("Enter the integer value to find ('q' to quit) : ");
        scanf("%s", userInput);
        if ((sscanf(userInput, "%d", &valToFind)) != 1) {
            if ((userInput[0] == 'q' || userInput[0] == 'Q') && userInput[1] == '\0') {
                printf("%s: Bye \n", basename(argv[0]));
                return EXIT_SUCCESS;
            } else {
                printf("%s: Invalid Input\n", basename(argv[0]));
            }
        } else {
            int valIndex = linearSearch(valToFind, dataIntArray, fileIntegerSize);
            if (valIndex == -1) {
                printf("%d was not found\n", valToFind);
            } else {
                printf("%d was found at position %d\n", valToFind, valIndex);
            }
        }
    }
    // freeing memory from the heap
    free(dataIntArray);
    return (EXIT_SUCCESS);
}

///*
// * An example of lots of error handling when reading an integer
// * value using strtol()
// *
// * (error messages should have gone to stderr).
// *
// * Dale Shpak, March 22, 2021
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//#include <limits.h>
//
//int main() {
//    printf("On this computer, a long is %d bytes and the maximum value is %ld\n", sizeof(long), LONG_MAX);
//    while (1) {
//	printf("Enter an integer value (that can be insanely huge): ");
//	char s[101];
//	scanf("%100s", s); // Read a maximum of 100 chars.  Safety mechanism for the array s.
//
//	char *endPtr;
//	errno = 0; // Reset global error number
//	long val = strtol(s, &endPtr, 10);
//	int errCode = errno; // save the error number
//	printf("Value read is: %ld", val);
//	fflush(stdout);
//	if (errCode == 0) {
//	    printf(" which will fit into a long\n");
//	} else{
//	    printf(" but an error was detected: %s\n", strerror(errCode));
//	}
//
//	if ((endPtr - s) < strlen(s)) {
//	    printf(" Stopped after reading %ld characters\n", (endPtr - s));
//	}
//	// Check if this long value will fit into an int
//	if (val > INT_MAX || val < INT_MIN) {
//	    printf("%s won't fit into a regular int\n", s);
//	} else {
//	    printf("%s will fit into a regular int\n", s);
//	}
//    }
//    return EXIT_SUCCESS;
//}